import os
import random
import sys
import string

converter = ['c', 's', 'd', 'i', 'u', 'p', 'u', 'x', 'X']

def gen_width():
    return(f'{random.randint(0,20)}')


def gen_width_precision():
    width = gen_width()
    return (f'{width}.')


def gen_width_precision_size():
    width_precision = gen_width_precision()
    return (f'{width_precision}{random.randint(0,100)}')


def gen_star_width():
    return ("*")


def gen_star_precision():
    return ('.*')

def gen_width_star_precision():
    width = gen_width()
    return (f'{width}{gen_star_precision()}')


def gen_size_star_precision():
    size = random.randint(0, 20)
    return (f'{gen_star_width()}.{size}')


gen_functions = {1: gen_width,
                 2: gen_width_precision,
                 3: gen_width_precision_size,
                 4: gen_width_star_precision,
                 5: gen_star_width,
                 6: gen_star_precision,
                 7: gen_size_star_precision,
                 }


def gen_flag():
    fun = random.choice([x for x in gen_functions])
    conv = random.choice(converter)
    flag = gen_functions[fun]()
    if '.' in flag and conv in 'pc':
        return (gen_flag())
    flag = f"{flag}{conv}"
    if '-' not in flag and random.randint(0,1):
        flag = f"-{flag}"
    if '-' in flag and flag[1] == '0':
        return (gen_flag())
    return (f"%{flag}")

def random_string():
    n = random.randint(1, 10)
    string = (''.join([chr(random.randint(32, 127)) for _ in range(n)]))
    if '"' in string or "'" in string or '%' in string or '|' in string or '\\' in string:
        return(random_string())
    return (string)

def gen_random_percentage():
    n = random.randint(1, 10)
    if n % 2:
        return (gen_random_percentage())
    percent = ('%' * n)
    string = chr(random.randint(32, 127))
    if string not in converter[:9]:
        return(f"{percent}")
    else:
        return (gen_random_percentage())


gen_input_function = {1: random_string,
                      2: gen_random_percentage,
                      3: gen_flag,
                      }

def gen_input():
    choice = [x for x in gen_input_function]
    flags = []
    result = ""
    for _ in range(random.randint(1, 10)):
        fun = gen_input_function[random.choice(choice)]
        flag = fun()
        if fun.__name__ == 'gen_flag' :
            flags.append(flag)
        result = f"{result}{flag}"
    return (result, flags)

def get_n_arguments(flags):
    i = 1
    result = []
    for f in flags:
        if '*' in f:
            result.append(f"{random.randint(-20,20)}")
            i += 1
        if f[-1] in "diuuxX":
            result.append(f"{random.randint(-10000,10000)}")
            i += 1
        elif f[-1] == "c":
            result.append(f"{random.randint(0,127)}")
            i += 1
        elif f[-1] == "s":
            result.append(f'"{random_string()}"')
            i += 1
        elif f[-1] == 'p':
            result.append(f"(void *){random.randint(-10000,10000)}")
    return (", ".join(result))

def build_printf(string, flags):
    arguments = get_n_arguments(flags)
    if len(arguments) > 0:
        my_fun = f'ft_printf("||{string}$",{arguments})'
        real_fun = f'printf("||{string}$",{arguments})'
        
    else:
        my_fun = f'ft_printf("||{string}$")'
        real_fun = f'printf("||{string}$")'
    my_fun = f'\n\tprintf("\t---- Return = %d ----", {my_fun});'
    real_fun = f'\n\tprintf("\t---- Return = %d ----", {real_fun});'
    result = f"{my_fun}{real_fun}"
    return (result, arguments)

def display_performances(length, n, ok, ko, name):
    state = round(n / length * 100) if n > 0 else 0
    onset = '['
    offset = ']'
    space = (100 - state) * '-'
    bar = state * '#'
    ok_perf = round(ok / n * 100, 2) if n > 0 else 0
    ko_perf = round(ko / n * 100, 2) if n > 0 else 0
    progress_bar = f"{name}{onset}{bar}{space}{offset}"
    performances = f"OK: {ok_perf}% -- KO: {ko_perf}%"
    print(f"{progress_bar} | {performances} ", sep='', end="\r", flush=True)

def display_header():
    header = f"{140 * '-'}\n"
    header = f"{header}\n\t\t\t\t\t\t\tPrintf Tests\n"
    header = f"{header}\n{140 * '-'}\n"
    header = f"{header}\nTests name\t\t\t\t\t       Tests progression\t\t\t\t\t         Performances\n"
    print(header)

def format(result_splitted, fun_input, args):
    output = 100 * "-"
    string = fun_input.split(',')[0]
    output = f'{output}\n\nInput\t\t\t: ft_printf("{string}", {args})$'
    output = f"{output}\nft_printf\t\t: {result_splitted[1]}"
    output = f"{output}\nprintf\t\t\t: {result_splitted[2]}"
    output = f"{output}\n\n[OK]" if result_splitted[1] == result_splitted[2] else f"{output}\n\n[KO]"
    output = f"{output}\n\n{100 * '-'}"
    return (output)

def build_library():
    os.system(f"make re")

def build_main(n_test):
    with open('deepthought', 'w+') as trace:
        for i in range(n_test):
            with open(f"main.c", "w+") as f:
                f.write('#include <stdio.h>\n#include "libftprintf.h"\n')
                f.write('int main(void)\n{')
                fun_input, flags = gen_input()
                printf,args = build_printf(fun_input, flags)
                f.write(printf)
                f.write('\n\treturn (0);\n}')
            os.system("gcc -Wall -Wextra -Werror main.c libftprintf.a")
            result = os.popen("./a.out | cat -e").read()
            result_splitted = result.split('||')
            output = format(result_splitted, fun_input, args)
            output = f"\n\nTest {i}\n{output}"
            print(output)
            if '[KO]' in output:
                trace.write(output)


if __name__ == '__main__':
    path = '../'
    build_library()
    display_header()
    build_main(int(sys.argv[1]))

#!/usr/bin/python3
'''pep8'''
import sys


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: read_write_heap.py pid search_string replace_string')
        exit(1)
    pid = sys.argv[1]
    str = sys.argv[2]
    rep = sys.argv[3]

    try:
        maps = open('/proc/{}/maps'.format(pid), 'r')
    except Exception as error:
        print(error)
        exit(1)

    try:
        me = open('/proc/{}/mem'.format(pid), 'r+b', 0)
    except Exception as error:
        maps.close()
        print(error)
        exit(1)

    for line in maps.readlines():
        line_split = line.split()
        if '[heap]' in line_split:
            mem = line_split[0].split('-')
            a = int(mem[0], 16)
            b = int(mem[1], 16)
            me.seek(a)
            x = me.read(b - a)
            pos = x.find(str.encode(str))

            if pos == -1:
                break

            me.seek(a + pos)
            me.write(str.encode(rep) + b'\x00')
            break

    me.close()
    maps.close()

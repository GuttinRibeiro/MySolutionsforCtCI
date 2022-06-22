def replace_blank_spaces(string: str, n: int)->str:
    ret = ''
    for i in range(n):
        if string[i] == ' ':
            ret += '%'
            ret += '2'
            ret += '0'
        else:
            ret += string[i]
    
    return str(ret)

def main():
    string = input('Input string: ')
    length = int(input('Size: '))
    print(f'Output: {replace_blank_spaces(string, length)}')

if __name__ == '__main__':
    main()
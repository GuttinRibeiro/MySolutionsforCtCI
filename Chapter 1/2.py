def string_to_dict(s: str)->dict:
    ret = {}
    for letter in s:
        if letter in ret:
            ret[letter] += 1
        else:
            ret[letter] = 1

    return ret

def check_permutation(s1: str, s2: str)->bool:
    dict_s1 = string_to_dict(s1)
    dict_s2 = string_to_dict(s2)

    for letter in dict_s1:
        if letter not in dict_s2:
            return False
        if letter in dict_s2 and dict_s2[letter] != dict_s1[letter]:
            return False
    
    return True

def main():
    s1 = input('First string: ')
    s2 = input('Second string: ')
    print(f'{s1} is a permutation of {s2}? {check_permutation(s1, s2)}')

if __name__ == '__main__':
    main()
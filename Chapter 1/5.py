def string_to_dict(s: str)->dict:
    ret = {}
    for letter in s:
        if letter in ret:
            ret[letter] += 1
        else:
            ret[letter] = 1

    return ret

def check_one_away(s1: str, s2: str)->bool:
    d1 = string_to_dict(s1)
    d2 = string_to_dict(s2)

    if len(d1.keys()) != len(d2.keys()):
        return False

    edits = 0
    for letter in d1:
        if letter not in d2:
            edits += 1
        else: 
            edits += abs(d2[letter]-d1[letter])

        if edits > 1:
            return False
        
    return True

def main():
    s1 = input('Input the first string: ')
    s2 = input('Input the second string: ')

    print(f'{s1} is one edit away from {s2}: {check_one_away(s1, s2)}')

if __name__ == '__main__':
    main()
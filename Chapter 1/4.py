def check_palindrome_permutation(s: str)->bool:
    cnt = {}
    for char in s:
        if char != ' ':
            if char.lower() not in cnt:
                cnt[char.lower()] = 1
            else:
                cnt[char.lower()] += 1


    odd_char = 0
    for char in cnt:
        if cnt[char] % 2 == 1 and odd_char == 0:
            odd_char += 1
        elif cnt[char] % 2 == 1:
            return False

    return True

def main():
    s = input('Input string: ')
    print(f'{s} is a permutation of a palindrome: {check_palindrome_permutation(s)}')

if __name__ == "__main__":
    main()
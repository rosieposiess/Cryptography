from curses.ascii import islower, isupper

def caesar_encrypt(pt,key=0):
    ct="" #이런식으로 문자열 초기화
    for c in pt:
        if c.isupper():
           c=c.lower() #lower() c 값 자체를 변경하지는 않음
           c=chr((ord(c)-97+key)%26+97)
           c=c.upper()
           ct=ct+c
        else:    
            c=chr((ord(c)-97+key)%26+97)
            ct=ct+c
    return ct
    

pt=input("Enter a string you want to encrypt:")
key=int(input("Enter your key(1~26):"))
ct=caesar_encrypt(pt,key)
print(ct)


#아직 미완
from curses.ascii import islower, isupper

def caesar_encrypt(pt,key=0):
    ct="" #이런식으로 문자열 초기화
    for c in pt:
       if isupper(c):
           c=islower(c)
           c=chr((ord(c)-97+key)%26+97)
           c=isupper(c)
       else:    
            c=chr((ord(c)-97+key)%26+97)
    ct+=c
    return ct

pt=input("Enter a string you want to encrypt:")
key=int(input("Enter your key(1~26):"))
caesar_encrypt(pt,key)
print(ct)



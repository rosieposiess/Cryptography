from base64 import encode
from Crypto.Cipher import DES3
from Crypto.Hash import SHA256 as SHA 
#3DES의 키와 IV 만들기 위해서 import


class myDES(): 
    #enc() ,dec() 정의
    def __init__(self,keytext,ivtext):
        #인자로 키 생성을 위한 문자열과 초기화 벡터 생성을 위한 문자열을 넣어줌
        hash=SHA.new() #SHA 객체 생성
        hash.update(keytext.encode('utf-8'))#인코딩된 값을 넣어주어야함
        key=hash.digest()
        self.key=key[:24] #3DES의 key는 16byte나 24byte이므로 슬라이싱 해줌
        
        hash.update(ivtext.encode('utf-8'))
        iv=hash.digest()
        self.iv=iv[:24]
        
    def enc(self,plaintext):
        des3=DES3.new(self.key,DES3.MODE_CBC(self.iv)) #DES3.new의 인자는 키,운영모드,iv
        encmsg=des3.encrypt(plaintext.encode())
        return encmsg
    
    def dec(self,ciphertext):
        des3=DES3.new(self.key,DES3.MODE_CBC,self.iv)
        decmsg=des3.decrypt(ciphertext)
        return decmsg
    

def main():
    key='samjang'
    iv='1234'
    msg='python3x'
    
    myCipher=myDES(key,iv)
    ct=myCipher.enc(msg)
    pt=myCipher.dec(ct)
    
    print('ORIGINAL:\t%s',msg)
    print('CIPHERED:\t%s',ct)
    print('DECIPHERED:\t%s',pt)

main()

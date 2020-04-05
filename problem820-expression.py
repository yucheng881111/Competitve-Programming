
from sys import stdin,stdout

while(True):
    ans=0
    s=stdin.readline()
    if(s==''):
        break
    li=[x for x in s if x=='+' or x=='*']
    s=s.replace('*','+')
    s=s.split('+')
    j=0
    ans=int(s[0])
    for i in range(1,len(s)):
        if(li[j]=='+'):
            ans+=int(s[i])
        else:
            ans*=int(s[i])
        j+=1
    stdout.write(str(ans))
    stdout.write('\n')
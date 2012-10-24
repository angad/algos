import math;

def permutate(s):
    if s:
        results = []
        for i in range(len(s)):
            for perms in permutate(s[:i] + s[i+1:]):
                results.append(s[i] + perms);
        return results
    else:
        return [""]

def paranthesis(length):
    s = "";
    for i in range(length):
        s += "(";
        s += ")";

    all = permutate(s);
    all = list(set(all))
    print all
    print len(all)
    
    opened = 0; closed = 0;
    
    for s in all:         
        opened = 0; closed = 0;
        for i in range(len(s)):
            if s[i] == '(':
                opened +=1;
            if s[i] == ')':
                closed +=1;
            if(closed > opened):
                all.remove(s)
                break;
            
    return all

def power(x, n): 
    result = 1;
    for i in range(n):
        result*=x
    return result

def powerFast(x, n):
    if(n==0): return 1;
    if(n%2==0): return (powerFast(x, n/2) * powerFast(x, n/2))
    if(n%2==1): return (powerFast(x, n/2) * powerFast(x, n/2) * x)    

def powerRecurs(x, n):
    if(n == 0): return 1;
    return x * powerRecurs(x, n-1)

def toBinary(n):
    results = []
    for i in range(int(math.pow(2, n))):
        t = i
        c = 0
        binary = []
        while t!=0:
            c +=1
            dig = t%2;
            t = t/2;
            binary.append(dig)
        for j in range(n - c):
            binary.append(0)
        binary.reverse()
        results.append(binary)
    return results
    
def powerset(s):
    results = []
    for bin in toBinary(len(s)):
        a = []
        c = 0
        for i in bin:
            if i:
                a.append(s[c])
            c+=1
        results.append(a)
    return results

def sumList(a):
    sum = 0
    for i in a:
        sum+=i
    return sum

def sum0(s):
    a = powerset(s)
#    print a
    for i in a:
        if(len(i)==3):
            print sumList(i)

def mergesort(s):
    l = len(s)
    left = s[:l/2]
    right = s[l/2:]
    if l > 1:
        left = mergesort(left)
        right = mergesort(right)
        return merge(left, right)
    else:
        return s
    
def merge(left, right):
    j = 0
    result = []
    if left and right:
        while len(left) > 0 or len(right) > 0:
            if(len(left) > 0 and len(right) > 0):
                if(left[0] <= right[0]):
                    result.append(left[0])
                    left = left[1:]
                else: 
                    result.append(right[0])
                    right = right[1:]
            elif(len(left) > 0):
                result.append(left[0])
                left = left[1:]
            elif(len(right) > 0):
                result.append(right[0])
                right = right[1:]
    return result


def main():
#    a = ['a', 'b', 'c', 'd']
    a = [5,4,3,7,8,3,5,7,9,4,2]
    print mergesort(a)
#    sum0(a)
#    print powerset(a)

if __name__ == "__main__":
    main()
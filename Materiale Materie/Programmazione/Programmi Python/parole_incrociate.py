str_1=input("inserire prima stringa: ")
str_2=input("inserire seconda stringa: ")


for i in range(0,len(str_1)):
    if str_1[i] in str_2:
        print(str_1[i],end='')
        print(str_2)
    else:
        print(str_1[i])
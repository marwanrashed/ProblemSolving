
State ='straight'
for i in range (1,101):
    if (i%15) == 0:
        Number = 10 if i%10 ==0 else i%10
        print ('Player Number: ', Number, "Does he?")
        if State == 'straight':
            State = 'reverse'
        elif State == 'reverse':
            State = 'straight'
    if ((i%15) !=0) and (State == 'straight'):
        if (i%2) ==0:
            Number = 10 if i%10 ==0 else i%10
            print ('Player Number: ', Number, "Ducky Fuzz")
        elif (i%2) != 0:
            Number = 10 if i%10 ==0 else i%10
            print ('Player Number: ', Number, "Fuzzy Duck")

    elif ((i%15) !=0) and (State == 'reverse'):
        if (i%2) ==0:
            Number = 10 - (i%10)
            print ('Player Number: ', Number, "Fuzzy Duck")
        elif (i%2) != 0:
            Number = 10 - (i%10)
            print ('Player Number: ', Number, "Ducky Fuzz")

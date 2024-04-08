'''
This file contains functions for all the questions we have previously solved in the class and for assignments.

If there is a error let me know.
'''

def week3():
    # 2-1
    message = "yasaswin"

    print("2-1 Your assigned message is : ", message)


    # 2-2

    message = 'yasaswin'
    print("2-2 (I) Your assigned message before modifying is : ", message)
    message = 'yash'
    print("2-2 (II) Your assigned message after modifying is : ", message)

    # 2-3
    name = input("Enter your name:")
    print("2-3 Hey " + name + "! are you getting used to python?")

    # 2-4
    name = input("Enter your name:")
    print("2-4 (I) Name in Lower Case : ", name.lower())
    print("2-4 (II) Name in Upper Case : ", name.upper())
    print("2.4 (III) Name in Title Case: ", name.title())


    # 2-5
    quote = 'Charlie Chaplin once said,"I always like walking in the rain, so no one can see me crying."'
    print("2-5 Quote is : "+quote)

    # 2-6
    quote = '"I always like walking in the rain, so no one can see me crying."'
    person = 'Charlie Chaplin'
    print("2-6 Quote is : "+person+" once said,"+quote)


    # 2-7
    # '\t' is to add whitespace before and '\n' is to change to a new line.
    name2 = "\tYasaswin Palukuri\n"
    print("The actual string is:", name2)
    print('2-7 (I) using lstrip ( removes the first "\\t"):', name2.lstrip())
    print('2-7 (II) using rstrip ( removes the first from the right hand side "\\n"):', name2.rstrip())
    print('2-7 (III) using strip ( removes all the trailing):', name2.strip())


    # 2-8
    print("\n")
    print("2-8 (I) Addition (4+4)=", (4+4))
    print("2-8 (II) Subtraction (16-8)=", (16-8))
    print("2-8 (III) Multiplication (4*2)=", (4*2))
    print("2-8 (IV) Integer Division (32//4)=", (32//4))


    # 2-9
    print("\n")
    num = int(input("Enter a number: "))
    var = "My favorite number is " + str(num)
    print("2-9 printing my favorite number:", var)

def week4():
    # Yasaswin Palukuri C0928450
    # Class Task 3  - Week 4

    # Lists

    print("3-4")
    guests = ["Sai", "Siva", "Suptha","Lalith"]
    for i in range(len(guests)):
        print("Hi " + guests[i] + ", I would like to invite you for dinner")

    print("\n3-5")
    print(f'{guests[2]}' ,"can\'t make it to the dinner")
    print("Updating names of the guests")
    guests[2] = "Yash"
    for i in range(len(guests)):
        print("Hi " + guests[i] + ", I would like to invite you for dinner")

    print("\n3-6")
    print("found a place with bigger table to enjoy the meal:), Lets add more guests for more fun")
    guests.insert(0, "Jagan")
    guests.insert(3, "Dinesh")
    guests.append("Jignesh")
    for i in guests:
        print("Hi " + i + ", I would like to invite you for dinner")


    print("\n3-7")
    print("Sorry guys, i can only invite two people for dinner :(, Had a couple of changes in the availability.")
    print("Sorry " + guests.pop() + ", I can't invite you for dinner")
    print("Sorry " + guests.pop() + ", I can't invite you for dinner")
    print("Sorry " + guests.pop() + ", I can't invite you for dinner")
    print("Sorry " + guests.pop() + ", I can't invite you for dinner")
    print("Sorry " + guests.pop() + ", I can't invite you for dinner")
    print("Hi " + guests[0] + ", You are still invited for dinner")
    print("Hi " + guests[1] + ", You are still invited for dinner")
    #del guests # deletes the variable
    del guests[0]
    del guests[0]
    print("Printing to verify whether deletion was successful:",guests)

    print("\n3-8")
    place = ["Tirupati", "Manasarovar", "Venice", "Bangalore", "Andaman"]
    print("Original List:", place)
    print("Sorting the list:",sorted(place))
    print("Original order of the list:",place)
    print("Sorting list in descending order:",sorted(place,reverse=True))
    print("Original order of the list:",place)
    print("Reversing the list:")
    place.reverse()
    print("List after reversing:",place)
    print("Again reversing the list:")
    place.reverse()
    print("list after reversing (again reached its original order):",place)
    print("Sorting the list with sort() in alphabetical or ascending order:")
    place.sort()
    print("Sorting list ascendingly:",place)
    print("Sorting the list with sort() in reverse order:")
    place.sort(reverse=True)
    print("Sorting the already modified list in reverse order:",place)

    print("\n3-9")
    guests = ["Sai", "Siva"]
    print("No.of guests invited to dinner:",len(guests))


    print("\n3-10")
    print("Creatinga a list of people in my house")
    ppl = ['Suryanarayana','Kanyakumari','Jagan', 'Chandana', 'Dinesh','Suptha','Yasaswin']
    print("Family members before",ppl[4]," marraige:", ppl)
    ppl.append('Sukanya')
    print("Family members after",ppl[4]," marraige:", ppl)
    print("Updating list with proper couple pairs by placing them adjacent")
    ppl.insert(5,'Sukanya')
    ppl.pop() # removing the last element
    print("Family members after updating:", ppl)
    print("No.of family members:",len(ppl))
    print("After 2 years of marraige, we have a new members in the family")
    ppl.extend(['Jignesh','Nimesh'])
    print("For Fun, lets sort them by names(temporary sort):",sorted(ppl))
    print("Original order of the list:",ppl)
    print("Removing Suptha after her marraige")
    ppl.remove('Suptha') # removes the first occurance of the element
    print("Family members after updating:", ppl)
    print("No.of family members:",len(ppl))
    print("Count of Jagan in the family:",ppl.count('Jagan'))
    print("Index of Jagan in the family:",ppl.index('Jagan'))
    print("Clearing the list as the work is done :)")
    ppl.clear()
    print("Verifying if the list is cleared:",ppl)

    print("\nDictionary Practices")
    courses = {
        'AML 1114':'Data Science and Machine Learning',
        'AMl 1214':'Python Programming',
        'AML 1301':'Careers in Artificial Intelligence',
        'AML 1413':'Into to Artitificial Intelligence',
        'CBD 2214':'Big Data Fundamental Data Storage Networking',
        'COM 3013':'Professional Communications'
    }
    print("Courses offered in AIMT at Lambton College,Toronto:",courses)
    print("Printing it in table:")
    for x,y in courses.items():
        print("Course Code:",x,"<=>","Course Name:",y)
    print("Name of course with code AML 1413 has been updated to Introduction to Artificial Intelligence")
    courses['AML 1413'] = 'Introduction to Artificial Intelligence'
    print("Updated course names:")
    for x,y in courses.items():
        print("Course Code:",x,"<=>","Course Name:",y)


# here i am using an void function since it is only for printing
def tshirt(quote,size):
    print("\'",quote,"\'. Is to be printed on a ",size," t-shirt")

def tshirt(quote="I love python",size="L"):
    print("\'",quote,"\'. Is to be printed on a ",size," t-shirt")

def print_city(city,country="India"):
    print("Yasaswin is in ",country," country and ",city," city.")


def city_country(city,country):
    return '"'+city+'","'+country+'"'

def make_album(arname,aralbum,count=None):
    return dict(name=arname,album=aralbum,songs=count)

def make_album(arname,aralbum,count=None):
    return dict(name=arname,album=aralbum,songs=count)

def week5P1():
    # 4-1
    pizza = list(['cheese','veggie','pepperoni'])
    print("4-1")
    #printing list of pizza using for loop
    for p in pizza:
        print(p)

    # modified for loop with statement
    for p in pizza:
        print("I like ",p," pizza")
        
    print("I am really craving for an tasty pizza :)")

    # 4-2
    print("4-2")

    animals = ['lion','tiger','hyena']
    for animal in animals:
        print(animal)

    for animal in animals:
        print(animal," is a wild animal.")

    print("All these animals are carnivorous")

    # 4-3
    
    print("4-3")
    
    print("Printing numbers from 1 to 20:")
    for i in range(1,21):
        print(i,end=" ")

    # 4-4
    
    print("4-4")
    
    # initiallizing list with 1 to 1000000
    l = [i for i in range(1,1000001)]
    
    for i in l:
        print(i,end=' ')

    # 4-5
    print("4-5")
    
    l = [i for i in range(1,1000001)]
    print("Verifing min and max:")
    print("Min: ",min(l),",Max: ",max(l))
    
    print("Summing all the numbers in list:")
    print("Sum:",sum(l))
    
    # 4-6
    print("4-6")
    
    # range function -> range(start,end,step), here step means to jump how many values
    l = [i for i in range(1,20,2)]
    
    print("Printing values after using range(1,20,2) to fill the list:")
    for i in l:
        print(i,end=' ')
    
    print("")
    l = list(menu)
    print("Changing sandwich to bread omlet, and rice to noodles")
    l.append('bread omlet')
    l.append('noodles')
    l.remove('sandwich')
    l.remove('rice')
    print(l)
    menu = tuple(l)
    print(menu)

    # 8-3
    print("8-3")
    tshirt(quote = "Hi hello",size = 'L')
    tshirt("Hi there",'XL')

    # 8-4
    print("8-4")
    print("Calling default function without passing values:")
    tshirt()
    
    print("Calling default function with only size:")
    tshirt(size='M')
    
    print("Calling defualt function with only quote:")
    tshirt(quote="I am loving python:)")

    # 8-5
    print("8-5")
    print_city("Vizag")
    print_city(city="Toronto")
    print_city("New York","UK")


    # 8-6
    print("8-6")
    print(city_country("Vizag","India"))
    print(city_country("Toronto","Canada"))
    print(city_country("Columbia","Sri Lanka"))

    # 8-7
    print("8-7")
    
    d = make_album("Vizag","India")
    print(d)
    m = (make_album("Toronto","Canada"))
    print(m)
    
    m = (make_album("Columbia","Sri Lanka"))
    d = d | m
    print(d)
    print(make_album("Vizag","India",2))

    # 8-8
    print("8-8")
    while True:
        print("Hello would you like to enter the details(y/n):")
        ch = input()
        if ch == 'n' or ch == 'N':
            break
        print("Enter the name of an album:")
        name = input()
        print("Enter the album name:")
        album = input()
        print("Enter the no.of songs if known:")
        no = input()
        print(make_album(name,album,no))

def check(s1,s2):
    return s1 == s2   

def hit53(clr):
    if clr == 'green':
        print("Player earned 5 points")

def hit54(clr):
    if clr == 'green':
        print("Player earned 5 points")
    else:
        print("Player earned 10 points")

def hit55(clr):
    if clr == 'green':
        print("Player earned 5 points")
    elif clr == 'yellow':
        print("Player earned 10 points")
    else:
        print("Player earned 15 points")

def week5P2():
    # 5-1
    print("5-1")
        
    car = 'TOYOTA'
    print("actual value in 'car'=",car)
    print("1. car == 'TOYOTA'? I predict 'True'.")
    print(check(car,'TOYOTA'))
    print("2. car == 'BMW'? I predict 'False'.")
    print(check(car,'BMW'))
    
    car = 'BMW'
    print("actual value in 'car'=",car)
    print("3. car == 'BMW'? I predict 'True'.")
    print(check(car,'BMW'))
    print("4. car == 'AUDI'? I predict 'False'.")
    print(check(car,'AUDI'))
    
    car = 'AUDI'
    print("actual value in 'car'=",car)
    print("5. car == 'AUDI'? I predict 'True'.")
    print(check(car,'AUDI'))
    print("6. car == 'KIA'? I predict 'False'.")
    print(check(car,'KIA'))
    
    car = 'KIA'
    print("actual value in 'car'=",car)
    print("7. car == 'KIA'? I predict 'True'.")
    print(check(car,'KIA'))
    print("8. car == 'HYUNDAI'? I predict 'False'.")
    print(check(car,'HYUNDAI'))
    
    car = 'HYUNDAI'
    print("actual value in 'car'=",car)
    print("9. car == 'HYUNDAI'? I predict 'True'.")
    print(check(car,'HYUNDAI'))
    print("10. car == 'LEXUS'? I predict 'False'.")
    print(check(car,'LEXUS'))


    # 5-2
    car = "KIA"
    print("actual value in 'car'=",car)
    print("Checking equality and inquality:\nChecking 'car',\"KIA\":",end=" ")
    print(car == "KIA")
    print("Checking 'car',\"kia\":",end = " ")
    print(car == "kia")
    
    print("\nConverting 'car' to lower case.")
    car = car.lower()
    print("Updated 'car' value is:",car)
    print("Checking equality and inquality:\nChecking 'car',\"KIA\":",end=" ")
    print(car == "KIA")
    print("Checking 'car',\"kia\":",end = " ")
    print(car == "kia")
    
    n = 10
    print("\nChecking equality and inquality for numerical variables with operators:")
    print("Value of 'n' = ",n)
    print("Checking if 'n' is 10:",end=" ")
    if n == 10:
        print("Yes")
    else:
        print("No")
    
    print("Checking if 'n' is not 10:",end=" ")    
    if n != 10:
        print("Yes")
    else:
        print("No")
        
    print("Checking if 'n' is greater than 5:",end=" ")
    if n > 5:
        print("Yes")
    else:
        print("No")
    
    print("Checking if 'n' is less than 20:",end=" ")
    if n < 20:
        print("Yes")
    else:
        print("No")
    
    print("Checking if 'n' is greater than or equal to 10:",end=" ")
    if n >= 10:
        print("Yes")
    else:
        print("No")
    
    print("Checking if 'n' is less than or equal to 10:",end=" ")
    if n <= 10:
        print("Yes")
    else:
        print("No")
        
        
    print("\nChecking equality and inquality for numerical variables with 'or' and 'and' operators:")
    print("Checking if 'n' is greater than 5 and less than 20:",end=" ")
    if n > 5 and n < 20:
        print("Yes")
    else:
        print("No")
        
    print("Checking if 'n' is 10 or 20:",end=" ")
    if n == 10 or n == 20:
        print("Yes")
    else:
        print("No")
        
    l = [1,2,3,4,5]
    print("\nChecking if values are present in the list or not",l,":")
    print("Checking if 5 is in the list:",end=" ")
    if 5 in l: 
        print("Yes")
    else:
        print("No")
    print("Checking if 10 is in the list:",end=" ")
    if 10 in l: 
        print("Yes")
    else:
        print("No")

    # 5-3
    print("5-3")
    hit53("green")
    hit53("yellow")

    # 5-4
    print("5-4")            
    hit54("green")
    hit54("yellow")

    # 5-5
    print("5-5")
    hit55("green")
    hit55("yellow")
    hit55("red")

    # 5-6
    print("5-6")
    age = 22

    if age < 2:
        print("Baby")
    elif age >= 2 and age < 4:
        print("Toddler")
    elif age >= 4 and age < 13:
        print("Kid")
    elif age >= 13 and age < 20:
        print("Teenager")
    elif age >= 20 and age < 65:
        print("Adult")
    else:
        print("Elder")

    # 5-7
    print("5-7")
    l = list(['mango','orange','apple'])

    if 'apple' in l:
        print("you really like apple.")
    if 'guava' in l:
        print("you really like guava.")
    if 'orange' in l:
        print("you really like orange.")
    if 'grapes' in l:
        print("you really like grapes.")
    if 'Watermelon' in l:
        print("you really like watermelon.")


    # 5-8
    print("5-8")
    
    users = list(['yash','admin','sai','suptha','lalith'])
    
    for l in users:
        if l == 'admin':
            print("Hello admin, would you like to check status of others.")
        else:
            print(f'Hello {l}, Welcome your logged in')


    #5-9
    print("5-9")
    
    l = list(['yash','admin','sai',''])
    l.clear()
    if len(l) == 0:
        print("We need to find some users!!!!")

    # 5-10
    print("5-10")

    users = list(['yash','admin','sai','suptha','lalith'])
    new_users = list(['hello','hi','SAI','siva','LaLiTh'])

    u = [i for i in users]
    for i in u:
        i = i.lower()
        
    for l in new_users:
        # print(l)
        if l.lower() in u:
            print("Please select new username")
        else:
            print("username avaialble")
    
    #5-11
    print("5-11")

    l = [i for i in range(1,10)]
    print("Printing in same line:")
    for i in l:
        if i == 1:
            print("1st",end=' ')
        elif i == 2:
            print("2nd",end=" ")
        elif i == 3:
            print("3rd",end=" ")
        else:
            print(str(i)+"th",end=' ')
            
            
            
    print("\nPrinting in new line each case:")
    for i in l:
        if i == 1:
            print("1st")
        elif i == 2:
            print("2nd")
        elif i == 3:
            print("3rd")
        else:
            print(str(i)+"th")


    

def week8():
    return


def main():
    while(True):
        print("===Python Programming Solutions===")
        print("1. Week 3")
        print("2. Week 4")
        print("3. Week 5 Part 1")
        print("4. Week 5 Part 2")
        print("5. Week 8")
        print("6. Exit")
        ch = int(input("Enter your choice: "))
        if ch == 1:
            week3()
        elif ch == 2:
            week4()
        elif ch == 3:
            week5P1()
        elif ch == 4:
            week5P2()
        elif ch == 5:
            week8()
        elif ch == 6:
            break
        else:
            print("Invalid choice. Please try again.")




if __name__ == "__main__":
        main()
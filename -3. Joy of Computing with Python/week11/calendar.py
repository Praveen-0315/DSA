import calendar

def check_leap(year):
    if year%100 == 0:
        if year%400 == 0:
            return True
    else:
        if year%4 == 0:
            return True
    return False

def check_valid_date(d, m, y, leap):
    if leap:
        if m ==2:
            if d<30:
                return True
            else:
                return False
    if leap == False:
        if m ==2:
            if d<29:
                return True
            else:
                return False
        
    if m<8:
        if m%2 == 1:
            if d<32:
                return True
            else:
                return False
        else:
            if d<31:
                return True
            else:
                return False
    else:
        if m%2 == 0:
            if d<32:
                return True
            else:
                return False
        else:
            if d<31:
                return True
            else:
                return False

def get_day(day_idx):
    list_of_days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

    return list_of_days[day_idx]

while(True):
    year = int(input('Enter an year (from 1970): '))
    if year<1970:
        print('Enter an year from 1970 ')
    else:
        break

while(True):
    month = int(input('Enter a month (1-12): '))
    if month<=12 and month>0:
        break
    else:
        print('Enter a valid month (1-12)')

leap = check_leap(year)

while(True):
    date = int(input('Enter date: '))
    if check_valid_date(date, month, year, leap):
        break
    else:
        print("Enter a valid date: ")

day_index = calendar.weekday(year, month, date)
day = get_day(day_index)

print(date,"/",month,"/",year,"falls on ",day)
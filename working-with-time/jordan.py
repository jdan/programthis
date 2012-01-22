#!/usr/bin/python

def main():
    months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    days_of_wk = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'] # start on Monday
    days_in_mo = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    # January 1st, 1 AD was a Monday
    month = int(raw_input("Enter a month (1-12): "))
    day = int(raw_input("Enter a day (1-%s): " % days_in_mo[month-1]))
    year = int(raw_input("Enter a year (> 0): "))
    
    days_since = 365 * (year - 1) # 365 days for each year up until the current year (we started at year 1)
    for m in range(0, (month - 1)):
        days_since += days_in_mo[m] # add all the days up until the current month
        
    days_since += day # add in the days from the current month
    
    # don't forget about leap years!
    # 1 day for every 4 years except centuries EXCEPT years divisible by 400
    
    days_since += (year / 4) - (year / 100) + (year / 400)
    days_since -= 1 # since we started on January 1st, 1 AD
    
    print '%s %s, %s is a %s' % (months[month-1], day, year, days_of_wk[days_since % 7])
    
if __name__ == '__main__':
    main()
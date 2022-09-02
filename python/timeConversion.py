def timeConversion(s):
    if 'PM' in s:
        if s[:2] == '12':
            return s[:8]
        else:
            hour = int(s[:2]) + 12
            return str(hour) + s[2:8]
    if 'AM' in s:
        if s[:2] == '12':
            return '00' + s[2:8]
        else:
            return s[:8]

# print(timeConversion('07:05:45PM'))
# print(timeConversion('12:05:45AM'))
# print(timeConversion('12:05:45PM'))



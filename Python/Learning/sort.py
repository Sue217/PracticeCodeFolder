lst = [1, 3, 2, 9, 0, 4, 7, 3, 5]
result = []
for x in lst :
    result.append(x)
result.sort()
for x in result :
    print(x, end = ' ')
print("")
result.sort(reverse = True)
for x in result :
    print(x, end = ' ')
print("")

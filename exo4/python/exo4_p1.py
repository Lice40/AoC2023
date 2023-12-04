with open("day_04.in") as fin:
    data = fin.read()
    lines = data.strip().split("\n")

n = len(lines)
m = len(lines[0])

def remove_items(lst:[str], element:str)->[str]:
    res = [i for i in lst if i!=element]
    return res


def process_game(line:str)->int:
    sum = 0
    datas:list(str) = line.split("|")
    guess = remove_items(datas[0].split(' '), '')
    winning_numbers = remove_items(datas[1].split(' '),'')
    print("guess: ", guess)
    print("data: ", winning_numbers)
    for number in guess:
        if number in winning_numbers:
            if sum == 0:
                sum = 1
            else:
                sum *= 2
    return sum

#démarage du programme
if __name__ == '__main__':
    result = 0
    for i, line in enumerate(lines):
        working_line = line.split(":")[1][1:]
        result += process_game(working_line)
    print (result)
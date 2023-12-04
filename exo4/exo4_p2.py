with open("day_04.in") as fin:
    data = fin.read()
    lines = data.strip().split("\n")

n = len(lines)
m = len(lines[0])
copies = [1]*len(lines)
def remove_items(lst:[str], element:str)->[str]:
    res = [i for i in lst if i!=element]
    return res


def process_game(line:str, cps, idx):
    wins = 0
    datas:list(str) = line.split("|")
    guess = remove_items(datas[0].split(' '), '')
    winning_numbers = remove_items(datas[1].split(' '),'')
    for i in range(0,cps):
        wins = 0
        for number in guess:
            if number in winning_numbers:
                wins +=1
        for number in range(idx+1, idx+wins+1):
            if(number < len(lines)):
                copies[number]+=1

#démarage du programme
if __name__ == '__main__':
    result = 0
    for i, line in enumerate(lines):
        working_line = line.split(":")[1][1:]
        process_game(working_line, copies[i], i)
    print(copies)
    print(sum(copies)+len(copies))         
    print (sum(copies))
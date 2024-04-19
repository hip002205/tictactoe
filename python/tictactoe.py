def initial_step():
    game_count = 0
    
    global array
    array = [['-' for j in range(3)] for i in range(3)]

def display_output():
    global array
    for i in array:
        print(i)

def game_play():
    global count
    count = 0
    initial_step()
    display_output()
    
    while True:
        input_p()
        if count >= 3 and check() == True:
            result()
            if retry() == False:
                break
            else:
                game_play()

def input_p():
    global count
    global array

    while True:
        input_x = input()
        input_y = input()

        if not input_x or input_x == ' ':
            input_x = 0
        
        if not input_y or input_y == ' ':
            input_y = 0

        x = int(input_x)
        y = int(input_y)

        if x >= 1 and x <= 3 and y >= 1 and y <= 3:
            if array[x - 1][y - 1] == '-':
                if count == 0 or count % 2 == 0:
                    array[x - 1][y - 1] = 'O'
                else:
                    array[x - 1][y - 1] = 'X'
                count+=1
                display_output()
                break
            else:
                print("同じマスには置けません。")
        else:
            print("範囲外")

def check():
    global array

    if array[0][0] == array[0][1] and array[0][1] and array[0][2] and array[0][0] != '-':
        return True

    elif array[1][0] == array[1][1] and array[1][1] == array[1][2] and array[1][0] != '-':
        return True

    elif array[2][0] == array[2][1] and array[2][1] == array[2][2] and array[2][0] != '-':
        return True

    if array[0][0] == array[1][0] and array[1][0] == array[2][0] and array[0][0] != '-':
        return True

    elif array[0][1] == array[1][1] and array[1][1] == array[2][1] and array[0][1] != '-':
        return True

    elif array[0][2] == array[1][2] and array[1][2] == array[2][2] and array[0][2] != '-':
        return True

    if array[1][1] != '-':
        if array[0][0] == array[1][1] and array[1][1] == array[2][2]:
            return True

        elif array[0][2] == array[1][1] and array[1][1] == array[2][0]:
            return True

def retry():
    while True:
        print("続けますか？続行:y 終了:n \n")
        inpt = input()

        if inpt == 'y':
            return True
        elif inpt == 'n':
            return False
        else:
            print("正しい値を入力してください。\n")

def result():
    global count

    if count % 2 == 1:
        print("〇の勝ち")
    
    elif count > 8:
        print("引き分け")

    else:
        print("×の勝ち")

def main():
    game_play()

main()
import paramiko

def readTxtFile(fileNm):
    file = open(fileNm + ".txt", "r", encoding="UTF-8")

    data = []
    while (1):
        line = file.readline()

        try:
            escape = line.index('\n')
        except:
            escape = len(line)
        if line:
            data.append(line[0:escape])
        else:
            break
    file.close()

    return data


def execCommands():
    cli = paramiko.SSHClient()
    cli.set_missing_host_key_policy(paramiko.AutoAddPolicy)
    cli.connect("192.168.0.1", port=22, username="아이디", password="패스워드")
    # 아이디랑 패스워드는 어디서 확인하는거지...그리고 접속하려는 기기의 ip주소를 받아오는 함수도 만들 수 있는건가?

    commandLines = readTxtFile("./commands/" + "파일명")  # 메모장 파일에 적어놨던 명령어 텍스트 읽어옴
    print(commandLines)

    stdin, stdout, stderr = cli.exec_command(";".join(commandLines))  # 명령어 실행
    lines = stdout.readlines()  # 실행한 명령어에 대한 결과 텍스트
    resultData = ''.join(lines)

    print(resultData)  # 결과 확인
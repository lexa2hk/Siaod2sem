import random
import string

file = open("T5Large.txt", "w")


def stringGen():
    return ''.join(random.choice(string.ascii_lowercase + string.ascii_uppercase) for _ in range(20)) + " " + random.randrange(0, 1000000000).__str__() + " " + random.randint(0, 1).__str__()

for i in range(300000):
    file.write(stringGen()+'\n')

file.close()

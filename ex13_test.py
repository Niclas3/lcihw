from subprocess import call

a = ["./ex13"]
for i in range(1, 262144-1):
    a.append('argsi')
call(a)

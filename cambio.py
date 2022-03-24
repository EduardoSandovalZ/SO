from sys import stderr
def cambio (cambio,tipo):
    billetes=cantidad //tipo
    resto=cantidad % tipo

    return billetes,resto

try:
    cantidad=int(input('Ingrese la cantidad de dinero: '))

    mon100, resto =cambio(cantidad,100)
    mon25, resto =cambio(resto,25)
    mon10,resto=cambio(resto,10)
    mon5, resto =cambio(resto,5)
    mon1, resto =cambio(resto,1)

    if mon100>0:
        print('(0) billetes de 100.'.format(mon100))
    if mon25>0:
        print('(0) billetes de 25.'.format(mon25))
    if mon10>0:
        print('(0) billetes de 10.'.format(mon10))
    if mon5>0:
        print('(0) billetes de 5.'.format(mon5))
    if mon1>0:
        print('(0) billetes de 1.'.format(mon1))
except ValueError as e:
    print('El valor introducido no es un entero.',file=stderr)

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
    print('(0)')

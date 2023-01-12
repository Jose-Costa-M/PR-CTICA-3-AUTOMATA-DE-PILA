'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.


no terminales: as var car let num ap c exp op sim bolos
terminales: a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z + - * / % = ;
1
var = exp ;

1
ap let car c

2 
let car 
lambda

26
a 
b 
c 
d 
e 


10
0 
1 
2
...


2 
( ap
lambda

2
) c
lambda


1 
ap var op c 

2 
sim ap var c op c 
lambda

5
+
- 
*
/ 
%


'''
import sys
#        METODOS
def validarpro(tipo,n,t,S, ps, sent):#tipo produccion, En, Et, S, ,produccion S,sentido
    aux=ps.split(" ")#Separamos los espacios
    S=S.split(" ")
    
    if(tipo==1):#si el tipo es 3
        if(sent==1):#si es por derecha
            if(len(aux) > 2 ):#Eliminamos espacios en la producción
                 return False #Si hay mas de dos simbolos rechazado
            elif(len(aux)==1):#Si solo hay un simbolo
                  if(aux[e] not in t):#Si no es terminal
                     return False
                  else:
                      return True
    elif(tipo==2):#Las condiciones no son sensibles al contexto
         return True
    elif(tipo==3):#condiciones son sensibles al contexto
      if (len(S) > 1): #Mayor a 1, por que en otro caso siempre estara bien su produccion
              if (len(S) == 2):
                  ok1 = False
                  ok2 = False
                  for x in aux:
                    if(x[0] == S[0]):
                      ok1 = True
                    else:
                      ok1 = False 
                    if(x[len(x) - 1] == S[len(aux) - 1]):
                      ok2 = True
                    else :
                      ok2 = False
                  ok = (ok1 or ok2)
                  return ok
              else:
                  ok = False 
                  for x in aux:
                    if((x[0]==S[0])and(x[len(x)-1] == S[len(s)-1])):
                      ok = True
                    else:
                      ok = False
                  return ok
      else:
        return True
    else:
      if (S == "lambda"):
        return False
        
def Imprimirtipo3(tipo, pa, pr):#IMprimimos tipo 3
  i = 0;
  print("                          S")
  for x in pa:
    for y in pr[x]:
      print(pr[x][i])
      if(len(pr[x]) > 2):
         print((i*" ") + str(y) + "  ")
         print((i*" ") + "   /   |     " + ch(92))
         print((i*" ") + "  /    |     " + ch(92))
         print((i*" ") + " /     |     " + ch(92))
      else:
         print((i*" ") + "   /         " + ch(92))
         print((i*" ") + "  /          " + ch(92))
         print((i*" ") + " /           " + ch(92))

      i+=1;

def imprimirtipo1(s,palabra,AlfEstNFinal):#Imprimir tipo 1
    p=''#se utiliza un auxiliar para guardar estados no terminales
    pa=[]#aqui se ponen estados luego serviran para juntarlos
    n=''
    for k in range(0,len(s)):#se utiliza backtraking para encontar el camino correcto
       n=n+s[k]+'    '
       if(s[k]in AlfEstNFinal):
           pa.append(s[k])
       else:
           palabra.remove(s[k])
    print(n)
    return pa,palabra


def Imprimirn(s,palabra,AlfEstNFinal):#Al igual que en tipo 1 se usa backtracking
  p = ''#se guarda estados y la posicion anterior
  pa=[]
  n=''
  for k in range(0,len(s)):
     n=n+s[k]+'   '
     if(s[k] in AlfEstNFinal): #se grafica usando libreria
       pa.append(s[k])
     else:
       palabra.remove(s[k])

  return pa,palabra,n

def imprimirpro(P):##no terminales y producciones
  for x in P:
    print(x,"--> ",P[x])

def producciones(tipo,n,t,sent):
  P={}#aquí guardaremos la lista de producciones de x
  condi=False
  print("Para escribir lambda escriba: lambda")
  for x in n:
     aux=[]#aquí guardaremos la lista de producciones de x
     num=int(input("Ingresar número de producciones de "+str(x)+": "))
     for y in range(num): #segun al numero de producciones de x
          pd = input(": ")# separamos los simbolos espaciando
          aux.append(pd)#agregamos la producción
          condi=validarpro(tipo,n,t,x,pd,sent)
     P[x]=aux
  imprimirpro(P)
  return P,condi #retornamos laS producciones y si esta correcta la produccion


def menutipo3():
    print()
    print("/"*10," TIPO 3 ","/"*10)
    print("1. POR DERECHA")
    print("2. POR IZQUIERDA")
    print("3. SALIR A MENU PRINCIPAL")
    print("0. SALIR DE PROGRAMA")
    return int(input("OPCION: "))


def Menu():
    print("="*10," MENU ","="*10)
    print("1. Gramatica regular (TIPO 3)")
    print("2. Gramatica Independiente de contexto (TIPO 2)")
    print("3. Gramatica sensible al contexto (TIPO 1)")
    print("4. Gramatica regular (TIPO 0)")
    print("0. SALIR")
    o = int(input("OPCION: "))
    return 2


o=Menu()


while(o!=0):
  oaux = 1
  if(o==2):
    n=input("Digite el conjuto de simbolos no terminales: ").split(" ")#sigma n
    t=input("Digite el conjunto de simbolos terminales: ").split(" ")#sigma 5
    P,condi=producciones(o,n,t,oaux)
    if(condi==False):
        print("Gramatica mal ingresada")
        break
    else:
        p=input("Digite la palabra: ")
        Imprimirtipo3(o,p,P)
 
o=Menu()        
    
    


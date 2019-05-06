import PYWrapper
#from PYWrapper import TestCallBack
import ClassTest

a = PYWrapper.A()
print(a.f())
ap = PYWrapper.APointer.create()
print(ap.hello())
aptr = PYWrapper.APointer.createSP()
print(aptr.hello())
apw = PYWrapper.APointer()
aw1 = apw.GetWorld()
aw2 = apw.GetWorld()
print("aw1:" + aw1.greet())
print("aw2:" + aw2.greet())
aw1.set("aw1")
aw2.set("aw2")
print("aw1:" + aw1.greet())
print("aw2:" + aw2.greet())

PYWrapper.greet()
planet = PYWrapper.World()
planet.set('tgest')
planet.greet()
pln = PYWrapper.World('con')
pln.greet()
x = PYWrapper.Var('pi')
x.value = 3.14
print (x.name, 'is around', x.value)


def t(sz):
    print(sz)
    
#PYWrapper.TestCallBack("py 2 c++",t)

def tr(sz,obj):
    print(sz)
    print(obj)
    obj.static_print()

try:
    name = PYWrapper.TestCallBack("py 2 c++",tr,ClassTest.Foo())
    print(name)
except TypeError as te:
    print(te)
except Exception as ex:
    print(ex)

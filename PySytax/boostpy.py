#import PYWrapper
from PYWrapper import *
import ClassTest

class PythonDerived(Base):
    def hello(self):
        return "Python hello"

        



#虚函数
a = A()
print(a.f())

#裸指针与智能指针，
ap = APointer.create()
print(ap.hello())
aptr = APointer.createSP()
print(aptr.hello())
apw = APointer()
#返回引用
aw1 = apw.GetWorld()
aw2 = apw.GetWorld()
print("aw1:" + aw1.greet())
print("aw2:" + aw2.greet())
aw1.set("aw1")
aw2.set("aw2")
print("aw1:" + aw1.greet())
print("aw2:" + aw2.greet())

#提取类
dumaw = exClass(aw1)
duwawlen = len(dumaw.nameV)
print(dumaw.nameV[0])
print("aw1:" + dumaw.greet())
#void*指针
use(get())
print(useany(get()))
print(useany(None))
print(useany(getnull()))



#全局函数，类属性方法
greet()
planet = World()
planet.set('tgest')
planet.greet()
planet.setP('ConstLuxiang')
planet.greet()
pln = World('con')
pln.greet()
x = Var('pi')
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
    name = TestCallBack("py 2 c++",tr,ClassTest.Foo())
    print(name)
except TypeError as te:
    print(te)
except Exception as ex:
    print(ex)

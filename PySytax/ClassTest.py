"""类的语法形式.类从objcet继承是新式类，区别可进一步学习"""

class Foo(object):    

    #类属性，在类中方法（也就是类中的函数）之外但又在类之中定义的属性
    Num = 0

    #构造函数，self.变量名作为实例属性
    def __init__(self):
        print("类构造")
        self.name = "lxxing"  #类的共有属性
        self.__age = 50       #类的私有属性

    def instance_print(self):
        #print("类实例方法，只能被实例对象调用".format(Foo))
        print("父类实例方法，只能被实例对象调用")
        Foo.Num += 1

    @staticmethod
    def static_print():
        print("静态方法")
        Foo.Num += 1
        Foo.__name__ = "LXXING"

    @classmethod
    def class_print(cls):
        print("类方法")
        cls.Num += 1
        cls.name = "class_print"

def SunFoo(Foo):
    Name = "SunFoo"

    def __init__(self):
        Foo.__init__(self)

    def instance_print(self):
        super(SunFoo,self).instance_print()
        print("子类实例方法，只能被实例对象调用")
        
print('---------实例测试-------')
foo = Foo()
foo.instance_print()
foo.static_print()
foo.class_print()
print('--------类测试--------')
Foo.static_print()
Foo.class_print()

print('--------属性测试--------')
print(Foo.Num)  #类属性
print(foo.name) #实例共有属性
print(foo._Foo__age)  #实例私有属性,不同版本命名规则不同，不建议这么做

print('---------子类测试-------')
sun = SunFoo(foo)
sun.instance_print()
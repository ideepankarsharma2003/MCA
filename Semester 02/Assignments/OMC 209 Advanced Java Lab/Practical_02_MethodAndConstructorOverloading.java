public class Practical_02_MethodAndConstructorOverloading {

    public Practical_02_MethodAndConstructorOverloading() {
        System.out.println("This is the default constructor.");
    }
    public Practical_02_MethodAndConstructorOverloading(String string){
        System.out.println("This is the overloaded constructor with argument "+ string);
    }

    public void printFunction(int  x){
        System.out.println("The integer is: "+ x);
    }
    public  void  printFunction (String s){
        System.out.println("The string is: "+ s);
    }

    public static void main(String[] args) {
        Practical_02_MethodAndConstructorOverloading obj1= new Practical_02_MethodAndConstructorOverloading();
        obj1= new  Practical_02_MethodAndConstructorOverloading("Dummy String");

        obj1.printFunction(3);
        obj1.printFunction("Dummy string");

    }
    
}

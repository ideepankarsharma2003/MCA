class Animal{

    public void speak() {
    System.out.println("The animal makes a sound.");
    }
    
}
class Dog extends  Animal{

    public void speak() {
    System.out.println("The dog barks.");
    }
    
}


public class Practical_05_MethodOverriding {
    public static void main(String[] args) {
        Animal animal= new Animal();
        Dog dog= new Dog();
        animal.speak();
        dog.speak();
    }
}

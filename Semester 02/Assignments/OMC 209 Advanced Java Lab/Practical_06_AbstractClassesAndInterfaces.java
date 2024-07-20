interface Talkable{
    public void talk();
}

abstract class Animal{
    String name;
    public Animal(String name) {
        this.name= name;
        System.out.println("This is a "+ name+ ", an Animal.");
    }
    
    abstract void move();
}

abstract class Reptile{
    String name;
    public Reptile(String name) {
        this.name= name;
        System.out.println("This is a "+ name+ ", a Reptile.");
    }
    
    abstract void crawl();
}


class Snake extends Reptile implements  Talkable{
    public  Snake(String name){
        super(name);
    }
    @Override
    public void talk(){
        System.out.println(this.name+ " hisses.");
    }
    @Override
    public  void  crawl(){
        System.out.println(this.name+ " crawls. ");
    }
}

class Cat extends Animal implements  Talkable{
    public  Cat(String name){
        super(name);
    }
    @Override
    public void talk(){
        System.out.println(this.name+ " meows.");
    }
    @Override
    public  void  move(){
        System.err.println(this.name+ " moves.");
    }
}


public class Practical_06_AbstractClassesAndInterfaces {
    public static void main(String[] args) {
        Snake snake= new Snake("Kaala Naag");
        Cat cat= new  Cat("Persian Tommy");
        cat.move();
        snake.crawl();
        snake.talk();
        cat.talk();
    }
}

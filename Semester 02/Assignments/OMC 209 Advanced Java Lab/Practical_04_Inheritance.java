/**
 * InnerPractical_04_Inheritance
 */
class Base{
    Base(){
        System.out.println("Base Class Constructor.");
    }
}

class LevelOneChild extends  Base{

    public LevelOneChild() {
    System.out.println("Level 1 child Constructor.");
    }
    
}

class LevelTwoChild extends  LevelOneChild{

    public LevelTwoChild() {
    System.out.println("Level 2 child Constructor.");
    }
    
}

public class Practical_04_Inheritance {
    public static void main(String[] args) {
       LevelTwoChild obj= new LevelTwoChild();
    }
}

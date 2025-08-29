class Animals{
    void sound(){
        System.out.println("animals makes sound");
    }
}
class Dog extends Animals{
    void sound(){
        System.out.println("Dogs barks");
    }
}
class Cat extends Animals{
    void sound(){
        System.out.println("Cats sound");
    }
}
// class Cow extends Animals{
//     void sound(){
//         System.out.println("cow sounds");
//     }
// }
public class inheritance{
    public static void main(String[] args){
        Dog dog=new Dog();
        Cat cat=new Cat();
        // Cow cow=new cow();
        
        dog.sound();
        cat.sound();
        Cow.sound();

        System.out.println("what sound an animal make");
        Animals animals=new Animals();
        animals.sound();
    }
}
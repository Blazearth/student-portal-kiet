package CODE_PRACTICE;

interface  Payment {
    void pay(double amount);//inheretly it is treated as 'public abstract void pay()'
    public  static void main(String[] args){
        Payment union=new Creditcard();
        Payment hdfc=new Paypal();
        union.pay(200000.9875);
        hdfc.pay(190000.9845);
    }
}

class Creditcard implements Payment{
    public void pay(double amount){//so that's why you need it to be public
        System.out.println("The amount to be paid $"+ amount+" by credit card is now paid");
    }
}
class Paypal implements Payment{
    public void pay(double amount){
        System.out.println("The amount to be paid $"+ amount+" by paypal is now paid");
    }
}


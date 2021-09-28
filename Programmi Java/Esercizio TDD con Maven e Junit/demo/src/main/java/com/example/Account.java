package com.example;

import java.util.ArrayList;
import java.util.Date;

public class Account {
    private static final int MAX_DEPOSIT = 300000;
    private static final int MIN_DEPOSIT = 1;
    
    private double balance;

    private ArrayList<Transaction> register;

    public Account(double balance) {
        this.balance = balance;
        register = new ArrayList<>();
    }

    public Account() {
        balance = 0;
        register = new ArrayList<>();
    }

    class Transaction {
        private String data;
        private double value;
        private double totalBalance;

        public Transaction(double value, double totalBalance) {
            Date currentData = new Date();

            data = currentData.toString();
            this.value = value;
            this.totalBalance = totalBalance;
        }

        public String getData() {
            return data;
        }

        public double getValue() {
            return value;
        }

        public double getTotalBalance() {
            return totalBalance;
        }
    }

    public boolean deposit(double value) {
        boolean check = true;

        if(value > MAX_DEPOSIT || value < MIN_DEPOSIT) {
            check = false;
            System.out.println("ERRORE: Il deposito deve avere un valore compreso tra 1 e 300.000 euro.");
        } else {
            balance += value;
            createTransaction(value, balance);
        }
        return check;
    }

    public boolean withdraw(int value) {
        boolean check = true;

        if(!(value % 10 == 0)) {
            check = false;
            System.out.println("ERRORE: il valore da prelevare deve essere multiplo di 10.");
        }

        if(value > balance) {
            check = false;
            System.out.println("ERRORE: il valore da prelevare deve essere inferiore al credito totale.");
        }

        if(value < 0) {
            check = false;
            System.out.println("ERRORE: il valore da prelevare deve essere positivo");
        }

        if(check){
            balance -= value;
            createTransaction(-value, balance);
        }

        return check;
    }

    public double getBalance() {
        return balance;
    }

    public void printTransactions() {
        for(int i = 0; i < register.size(); i++) {
            System.out.println(register.get(i).getData() + " " + register.get(i).getValue() + " " + register.get(i).getTotalBalance());
        }
    }

    private void createTransaction(double value, double balance) {
        register.add(new Transaction(value, balance));
    }

    public static void main(String[] args) {
        Account a = new Account();
        a.deposit(1000);
        a.withdraw(200);
        a.printTransactions();
    }

}

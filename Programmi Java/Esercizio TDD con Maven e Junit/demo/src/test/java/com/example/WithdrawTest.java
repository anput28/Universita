package com.example;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class WithdrawTest {
    Account account;

    @BeforeEach
    public void setup() {
        account = new Account(1000);
    }

    @Test
    @DisplayName("Withdraw with valid input")
    public void testCorrectWithdraw() {
        assertTrue(account.withdraw(10));
    }

    @Test 
    @DisplayName("Withdraw with positive multiple of 10 but over budget")
    public void testOverBudgetPositiveMultipleOfTen() {
        assertFalse(account.withdraw(1010));
    }

    @Test
    @DisplayName("Withdraw with negative multiple of ten")
    public void testNegativeMultipleOfTen() {

        assertFalse(account.withdraw(-10));
    }

    @Test
    @DisplayName("Withdraw with positive non multiple of ten")
    public void testPositiveNonMultipleOfTen() {
        assertFalse(account.withdraw(11));
    }

    @Test
    @DisplayName("Withdraw with positive overbudget non multiple of ten")
    public void testOverBudgetNonMultipleOfTen() {
        assertFalse(account.withdraw(1001));
    }

    @Test
    @DisplayName("Withdraw with negative non multiple of ten")
    public void testNegativeNonMultipleOfTen() {
        assertFalse(account.withdraw(-1));
    }

    @Test
    @DisplayName("Balance changes after withdraw")
    public void testBalanceChangesAfterWithdraw() {
        int balanceChanged = 800;
        account.withdraw(200);
        assertEquals(balanceChanged, account.getBalance());
    }
}

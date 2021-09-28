package com.example;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class DepositTest {
    Account accountMock;

    @BeforeEach
    public void setup() {
        accountMock = new Account(1000);
    }

    @Test
    @DisplayName("Deposit with valid value")
    public void testValidDeposit() {
        assertTrue(accountMock.deposit(1.10));
    }

    @Test
    @DisplayName("Deposit over the limit")
    public void testOverLimitDeposit() {
        assertFalse(accountMock.deposit(300001));
    }

    @Test
    @DisplayName("Deposit under the limit")
    public void testUnderLimitDeposit() {
        assertFalse(accountMock.deposit(-1));
    }

    @Test
    @DisplayName("Balance changes after deposit")
    public void testBalanceChangesAfterDeposit() {
        int balanceChanged = 1500;
        accountMock.deposit(500);
        assertEquals(balanceChanged, accountMock.getBalance());
    }
}

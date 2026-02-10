package com.fasoo.javafinch.syn.checker.android.forbidden;

import android.accounts.AbstractAccountAuthenticator;
import android.accounts.Account;
import android.accounts.AccountAuthenticatorResponse;
import android.accounts.AccountManager;
import android.accounts.NetworkErrorException;
import android.os.Bundle;

/**
 * KEPCO_RULE_208
 */

public class DoNotAccessAccountInformation {
    public void tester(AbstractAccountAuthenticator auth, AccountAuthenticatorResponse response, Account account, String authTokenType, Bundle options, String type, String key, String password, String value, AccountManager manager) {
        try {
            auth.getAuthToken(response, account, authTokenType, options); // @violation
        } catch(NetworkErrorException e) {
        }

        manager.getAccounts(); // @violation
        manager.getAccountsByType(type); // @violation
        manager.getPassword(account); // @violation
        manager.getPreviousName(account); // OK
        manager.getUserData(account, key); // @violation
        manager.setPassword(account, password); // @violation
        manager.setUserData(account, key, value); // @violation
    }
}

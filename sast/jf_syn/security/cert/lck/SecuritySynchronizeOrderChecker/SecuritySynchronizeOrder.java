package cert.lck;

final class SecuritySynchronizeOrder {
    private double balanceAmount;  // Total amount in bank account

    SecuritySynchronizeOrder(double balance) {
        this.balanceAmount = balance;
    }

    private void depositAmount(LCK07SecuritySynchronizeOrder ba, double amount) {
        synchronized (this) {                       // @violation
            synchronized (ba) {
                if (amount > balanceAmount) {
                    throw new IllegalArgumentException(
                            "Transfer cannot be completed"
                    );
                }
                ba.balanceAmount += amount;
                this.balanceAmount -= amount;
            }
        }

        synchronized (ba) {                         // @violation
            synchronized (this) {
                if (amount > balanceAmount) {
                    throw new IllegalArgumentException(
                            "Transfer cannot be completed"
                    );
                }
                ba.balanceAmount += amount;
                this.balanceAmount -= amount;
            }
        }
    }

    @Override
    public int compareTo(BankAccount ba) {
        return (this.id > ba.id) ? 1 : (this.id < ba.id) ? -1 : 0;
    }

    private void depositAmount_Good(LCK07SecuritySynchronizeOrder ba, double amount) {
        BankAccount former, latter;
        if (compareTo(ba) < 0) {
            former = this;
            latter = ba;
        } else {
            former = ba;
            latter = this;
        }
        synchronized (former) {                     /* Safe */
            synchronized (latter) {
                if (amount > balanceAmount) {
                    throw new IllegalArgumentException(
                            "Transfer cannot be completed");
                }
                ba.balanceAmount += amount;
                this.balanceAmount -= amount;
            }
        }
    }

    public static void initiateTransfer(final LCK07SecuritySynchronizeOrder first,
                                        final LCK07SecuritySynchronizeOrder second, final double amount) {

        Thread transfer = new Thread(new Runnable() {
            public void run() {
                first.depositAmount(second, amount);
            }
        });
        transfer.start();
    }
}
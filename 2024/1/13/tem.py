from enum import Enum
from datetime import date

class AccountType(Enum):
    NORMAL = 1
    VIP = 2
    SVIP = 3

class CreditCardUser:
    USERS = {}
    
    def __init__(self, user_id, password, type):
        self.user_id = user_id
        if type == AccountType.NORMAL:
            self.loan_limit = 1000
        elif type == AccountType.VIP:
            self.loan_limit = 10000
        elif type == AccountType.SVIP:
            self.loan_limit = 100000
        self.password = password
        self.credit_score = 1000
        self.last_borrow_date = None
        self.transaction_records = []
        CreditCardUser.USERS[user_id] = self

    @staticmethod
    def register(user_id, password, type):
        CreditCardUser.USERS[user_id] = CreditCardUser(user_id, password, type)
        raise NotImplementedError
    
    @staticmethod
    def login(user_id, password):
        user = CreditCardUser.USERS[user_id]
        if password != user.password:
            print('Wrong password!')
        else:
            print('User logged in successfully')
            return user

    def loan(self):
        """
        User engages in a loan transaction.
        
        Parameters
        ----------
        amount : int
            Loan amount.
        date : date_like
            Loan date.
        
        """
        raise NotImplementedError

    def repay(self):
        """
        User engages in a repayment transaction.
        
        Parameters
        ----------
        amount : int
            Loan amount.
        date : date_like
            Loan date.
        
        """
        raise NotImplementedError

    def query(self):
        return "\n".join(list(map(CreditCardUser.__record_to_string, self.transaction_records)))

    @staticmethod
    def __record_to_string(record):
        return f'{record["user_id"]},{record["date"]},{record["amount"]:+}'


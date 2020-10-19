#include <stdio.h>
#include <cs50.h>

int len_cred(long l_num);
int algo_check(long num);

int main(void)
{
    long cred_num = get_long("Credit: ");

    int card_leng = len_cred(cred_num);
    int sum = algo_check(cred_num);

    //Checking the validity of the card
    if((card_leng == 13 || card_leng == 15 || card_leng == 16) && (sum % 10 == 0))
    {
        //Checking what type of card is being passed
        //AMEX Requirements
        if ((cred_num > 34e13 && cred_num < 35e13) || (cred_num >37e13 && cred_num < 38e13))
        {
            if (sum %10 == 0)
            {
                printf("AMEX\n");
            }
        }
        //MasterCard Requirements
        else if ((cred_num > 51e14 && cred_num < 56e14))
        {
            if (sum %10 == 0)
            {
                printf("MASTER CARD\n");
            }
        }
        //Visa Requirements
        else if ((cred_num > 4e12 && cred_num < 5e12) || (cred_num > 4e15 && cred_num < 5e15))
        {
            if (sum %10 == 0)
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }


}

//Need to check the length of the credit card for validity
int len_cred(long l_num)
{
    int leng = 0;
    for (int i = 0;l_num !=0; l_num /= 10, i++)
    {
        leng++;
    }
    return leng;
}


//Have to loop through the credit card number by dividing by ten and updating. Need to also record the index
//Odd indexes will need to use the algo while evens are just added on
int algo_check(long num)
{
    int ttl_sum = 0;
    for (int i = 0;num != 0;num /= 10, i++)
    {
        if (i % 2 == 0)
        {
           ttl_sum += num % 10;
        }

        else
        {
            int dbl = (num % 10) * 2;
            ttl_sum += (dbl / 10 + dbl % 10);
        }
    }
    return ttl_sum;
}
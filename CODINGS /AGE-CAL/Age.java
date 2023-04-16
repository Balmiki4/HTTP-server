import java.util.Scanner;
import java.io.*;

public class Age {

    public static int AgeYear(int BirthYear, int AgeYear) {

        int CurrDate = 15;
        int CurrMonth = 12;
        int CurrYear = 2022;
        // int AgeYear = 0;
        // calculate age year
        AgeYear = CurrYear - BirthYear;
        return AgeYear;
    }

    public static void AgeMonth(int BirthYear) {
        int AgeYear = 0;
        int AgeMonth = 0;
        int AgeDays = 0;
        AgeMonth = CurrMonth - BirthMonth;
        if (AgeMonth < 0) {
            AgeYear--; // reduce age year by 1;
            AgeMonth = 12 - BirthMonth + CurrMonth;
            // if full cycle of month is incomplete
            if (CurrDate < BirthDate) {
                AgeMonth--; // reduce age month by 1
            }

        }
        // if full month is not completed than whole year is also not completed
        else if (AgeMonth == 0 && CurrDate < BirthDate) {
            AgeYear--;
            AgeMonth--; // reduce age month by 1

        } // else age month remains as it is in case of curentDate > BirthDate
          // and currentDate = BirthDAte
    }

    public static void AgeDate

    public static void input() {
        int BirthDate = 0;
        int BirthMonth = 0;
        int BirthYear = 0;
        // input user's date of birth
        while (BirthDate <= 0 || BirthDate > 30) {
            System.out.println("Enter date: ");
            BirthDate = obj.nextInt();
        }

        while (BirthMonth <= 0 || BirthMonth > 12) {
            System.out.println("Enter month: ");
            BirthMonth = obj.nextInt();
        }

        while (BirthYear <= 0 || BirthYear > 2022) {
            System.out.println("Enter year: ");
            BirthYear = obj.nextInt();
        }
        AgeYear(BirthYear);
        // calculate age month

        AgeMonth = CurrMonth - BirthMonth;
    }

    public static void main(String[] args) {
        int BirthDate = 0;
        int BirthMonth = 0;
        int BirthYear = 0;
        int CurrDate = 15;
        int CurrMonth = 12;
        int CurrYear = 2022;
        int AgeYear = 0;
        int AgeMonth = 0;
        int AgeDays = 0;
        Scanner obj = new Scanner(System.in);

        // input user's date of birth
        while (BirthDate <= 0 || BirthDate > 30) {
            System.out.println("Enter date: ");
            BirthDate = obj.nextInt();
        }

        while (BirthMonth <= 0 || BirthMonth > 12) {
            System.out.println("Enter month: ");
            BirthMonth = obj.nextInt();
        }

        while (BirthYear <= 0 || BirthYear > 2022) {
            System.out.println("Enter year: ");
            BirthYear = obj.nextInt();
        }
        // calculate age year
        AgeYear = CurrYear - BirthYear;
        // calculate age month

        AgeMonth = CurrMonth - BirthMonth;
        // if agemonth is negative than it means full year is not completed
        if (AgeMonth < 0) {
            AgeYear--; // reduce age year by 1;
            AgeMonth = 12 - BirthMonth + CurrMonth;
            // if full cycle of month is incomplete
            if (CurrDate < BirthDate) {
                AgeMonth--; // reduce age month by 1
            }

        }
        // if full month is not completed than whole year is also not completed
        else if (AgeMonth == 0 && CurrDate < BirthDate) {
            AgeYear--;
            AgeMonth--; // reduce age month by 1

        } // else age month remains as it is in case of curentDate > BirthDate
          // and currentDate = BirthDAte

        // calculate days
        if (CurrDate > BirthDate) {
            AgeDays = CurrDate - BirthDate;
        } else if (CurrDate < BirthDate) {
            // considering 30 days in a month
            AgeDays = 30 - BirthDate + CurrDate;

        }
        // if current date is equals to birth date
        else {

            AgeDays = 0;
            if (AgeMonth == 12) {
                AgeYear++;
                AgeMonth = 0;
            }

        }
        System.out.println(AgeYear + " Years " + AgeMonth + " Months " + AgeDays + " Days.");

    }

}
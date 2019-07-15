//Benjamin Chilson

#include <stdio.h>
#include <math.h>

typedef struct{
    //sideA AND sideB ARE THE SHORTER TWO SIDES OF THE TRIANGLE AND ARE NOT THE HYPOTENUSE
    float sideA;
    float sideB;
    //THE VARIABLE sideC IS RESERVED FOR THE HYPOTENUSE OF THE TRIANGLE
    float sideC;
} rightTriangle;

void findHypotenuse(rightTriangle *);
void findRemainingLeg(rightTriangle *);
void getLegs(rightTriangle *);
void getLegAndHypotenuse(rightTriangle *);
void viewTriangle(rightTriangle);

int main(void){
      //continueValue IS CHECKED TO SEE IF IT EQUALS 1 AT THE END OF THE DO-WHILE
	int continueValue;
	do{
            //VARIABLE MADE TO STORE THE USER'S MENU SELECTION CHOICE
		int menuChoice;

            //PRINTS TITLE AND INSTRUCTIONS TO SCREEN, THEN PROMPTS AND STORES USER INPUT
		printf("\n\n----WELCOME TO THE RIGHT TRIANGLE CALCULATOR----\n\nPlease select what variables you wish to input\n(1) two triangle legs\n(2) one triangle leg and one hypotenuse\nplease make a selection: ");
		scanf("%d", &menuChoice);

		//CHECKS USERS MENU SELECTION
		while(menuChoice != 1 && menuChoice != 2){
			printf("\nINVALID! Please enter a valid option: ");
			scanf("%d", &menuChoice);
            }

            //CREATES A rightTriangle VARIABLE THAT WILL STORE THE INFO GIVEN AND CALCULATED ABOUT THE USER'S TRIANGLE
            rightTriangle usersTriangle;

            switch(menuChoice){
                  //IF THE USER SELECTED option 1 TO PUT IN THE DATA FOR THE LEGS OF THEIR RIGHT TRIANGLE
                  case 1:
                        getLegs(&usersTriangle);
                        findHypotenuse(&usersTriangle);
                        break;

                  //IF THE USER SELECTED option 2 TO PUT IN THE DATA FOR A RIGHT TRIANGLE LEG AND THE HYPOTENUSE
                  case 2:
                        getLegAndHypotenuse(&usersTriangle);
                        findRemainingLeg(&usersTriangle);
                        break;
            }

            viewTriangle(usersTriangle);

            //ASKS IF USER WOULD LIKE TO CONTINUE
	      printf("\nWould you like to continue?\n(1) yes\n(2) no\nPlease make a selection: ");
	      scanf("%d", &continueValue);


            //CHECKS IF USERS CHOICE WAS VALID
            while(continueValue != 1 && continueValue != 2){
                  printf("\nINVALID! Please enter a valid option: ");
                  scanf("%d", &continueValue);
            }
            printf("----------------------------------\n");

      } while(continueValue == 1); //LOOPS IF USER WISHES TO CONTINUE (ENTERED 1), ENDS IF THEY DO NOT

      printf("\nHAVE A GREAT DAY!\n\n");

      return(0);
} //ENDS MAIN

void getLegs(rightTriangle *usersTriangle){
      do{
            //PROMPTS THE USER TO ENTER THE SIDE LENGTH OF THEIR TRIANGLE, THEN STORES THAT INFORMATION IN THE rightTriangle VARIABLE
            printf("\nPlease enter side length a: ");
            scanf("%f", &usersTriangle->sideA);

            //PRINTS ERROR MESSAGE IF THE LEG VALUE THE USER ENTERED WAS NEGATIVE OR ZERO
            if(usersTriangle->sideA <= 0){
                  printf("Please enter a positive value...\n");
            }
      }while(usersTriangle->sideA <= 0); //LOOPS PROMPT IF THE USERS ENTERED VALUE WAS INVALID

      do{
            //PROMPTS THE USER TO ENTER THE OTHER SIDE LENGTH OF THEIR TRIANGLE, THEN STORES THAT INFORMATION IN THE rightTriangle VARIABLE
            printf("\nPlease enter side length b: ");
            scanf("%f", &usersTriangle->sideB);

            //PRINTS ERROR MESSAGE IF THE OTHER LEG VALUE THE USER ENTERED WAS NEGATIVE OR ZERO
            if(usersTriangle->sideB <= 0){
                  printf("Please enter a positive value...\n");
            }
      }while(usersTriangle->sideB <= 0); //LOOPS PROMPT IF THE USERS ENTERED VALUE WAS INVALID
} //ENDS getLegs FUNCTION

void findHypotenuse(rightTriangle *usersTriangle){

    //CALCULATES a^2 AND b^2
    float sideASquared = pow(usersTriangle->sideA, 2);
    float sideBSquared = pow(usersTriangle->sideB, 2);

    //FINDS HYPOTENUSE USING PYTHAGOREAN THEOREM
    usersTriangle->sideC = sqrt(sideASquared + sideBSquared);

    //PRINTS EQUATION USED AND THE HYPTENUSE CALCULATED
    printf("\nCalculation: %.2f + %.2f = c^2\n", sideASquared, sideBSquared);
    printf("Hypotenuse length = %.2f\n", usersTriangle->sideC);
} //ENDS findHypotenuse

 void getLegAndHypotenuse(rightTriangle *usersTriangle){
       do{
             //PROMPTS THE USER TO ENTER THEIR HYPOTENUSE LENGTH AND STORES IN THE usersTriangle
             printf("\nPlease enter the length of the hypotenuse(Side C): ");
             scanf("%f", &usersTriangle->sideC);

             //CHECKS TO SEE IF USER ENTERED DATA IS VALID
             if(usersTriangle->sideC <= 0){
                   printf("Please enter a positive value...\n");
             }
      }while(usersTriangle->sideC <= 0); //CONTINUES TO PROMPT USER IF THEIR ENTERED HYPOTENUSE IS NOT VALID

       do{
             //PROMPTS THE USER TO ENTER THEIR SIDE LENGTH AND STORES IN THE usersTriangle
             printf("\nPlease enter side length A: ");
             scanf("%f", &usersTriangle->sideA);

             //CHECKS TO SEE IF USER ENTERED DATA IS VALID, THE HYPOTENUSE IS LARGER THAN THE SIDE LENGTH
             if(usersTriangle->sideC <= usersTriangle->sideA){
                 printf("Please enter a value less than the hypotenuse...\n");
             }
             //CHECKS TO SEE IF USER ENTERED DATA IS VALID, THE SIDE LENGTH IS POSITIVE
             else if(usersTriangle->sideA <= 0){
                 printf("Please enter a positive value...\n");
             }
      }while(usersTriangle->sideA <= 0 || usersTriangle->sideC <= usersTriangle->sideA); //REPEATS THIS LOOP IF EITHER VALIDITY CHECK PROOVES FALSE
 }

 void findRemainingLeg(rightTriangle *usersTriangle){
       //CALCULATES a^2 AND c^2
       float sideASquared = pow(usersTriangle->sideA, 2);
       float sideCSquared = pow(usersTriangle->sideC, 2);

       //FINDS REMAINING SIDE USING PYTHAGOREAN THEOREM
       usersTriangle->sideB = sqrt(sideCSquared - sideASquared);

       //PRINTS EQUATION USED AND REMAINING SIDE CALCULATED
       printf("\nCalculation: %.2f + b^2 = %.2f\n", sideASquared, sideCSquared);
       printf("Side B = %.2f\n", usersTriangle->sideB);
 } //ENDS findRemainingLeg

 void viewTriangle(rightTriangle usersTriangle){
       //PRINTS OUT ALL DATA STORED IN THE usersTriangle rightTriangle VARIABLE GIVEN TO THE FUNCTION
       printf("\nHere is the data we have of your triangle:\nSide A: %f\nSide B: %f\nSide C: %f\n", usersTriangle.sideA, usersTriangle.sideB, usersTriangle.sideC);
 } //ENDS viewTriangle

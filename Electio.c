#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void loarding_loop();
void loarding();

void voting_section();
int voting_status(int a, int b);
int vote_store(int x);
void voting_status_up(int rn, int cn);

void voter_data();
void status_voter();
char *n_to_course(int *n);
char cours_selec();
void Create_voterlist();
void display_voter();
void add_voter();
void del_voter();
void search_voter();
void no_voter();

void candidates_data();
void status_cand();
void Create_candlist();
void display_cand();
void del_cand();
void serch_cand();
void no_cand();

void voting_result();

void password_2();
void password_3();
void result();
void reset();

struct voter
{
    int reg_no;
    int cours; // structure for voters data
    int nic;
    char voter_name[30];
};

struct cand
{
    int nom_no; // structure for candidates data
    char cand_name[30];
};

void main()
{
    loarding(); // calling starting animation loarding
    int ch1;    // variable for get user choice

    int password1, choose;
    int *s = 0; // pointer for compare with NULL in a if condition
    do
    {
        // first menu
        printf("\n\n\t1.START\t0.exit\n");
        printf("\n<======================================================================================>\n");
        printf("=>Enter your choice:");
        scanf("%d", &choose); // get user choice for first menu

        switch (choose)
        {
        case 1:

            do
            {
                printf("\n<======================================================================================>\n");
                printf("=>Enter the password 1 :");
                scanf("%d", &password1); //  ask user to enter the  password 1
                if (password1 == 1111)
                {
                    do
                    {
                        // Display_main
                        printf("\n<=========================================Welcome to Main data Section=========================================>\n");
                        printf("\n\t1.Voting\t2.Voter data\t3.Candidates data\t4.Voting result\t5.Reset voting\t0.exit\t");
                        printf("\n<==============================================================================================================>\n");
                        printf("\n\n=>Enter your choice:");
                        scanf("%d", &ch1); // get user choice

                        switch (ch1)
                        {
                        case 1:
                            printf("\n<=========================================Welcome to Voting Section=========================================>\n");
                            voting_section(); // calling voting function
                            break;
                        case 2:
                            printf("\n<=========================================Welcome to Voter data Section=========================================>\n");
                            password_2(); // calling voter data function inside the password 2 function
                            break;
                        case 3:
                            printf("\n<=========================================Welcome to Candidates data Section=========================================>\n");
                            password_3(); // calling candidates data inside the password 3 function
                            break;
                        case 4:
                            printf("\n<=========================================Welcome to Voting Result Section=========================================>\n");
                            result(); // calling result function
                            break;
                        case 5:
                            printf("\n<=========================================Welcome to Voting Reset Section=========================================>\n");
                            reset(); // calling reset function
                            break;
                        default:
                            break;
                        }
                    } while (ch1 != 0); // if user enter 0 then exit until that display the main menu
                    *s = 1;
                }
                else
                    printf("\tInvalid password...!\a\n"); // if password 1 is wrong then print this with a alert sound
                printf("\n<======================================================================================>\n");
            } while (password1 == 1111 && s == NULL); // comparing the password 1 and s pointer for ask password from user first time only
        default:
            break; // if user did not input 1 or 0 then end this switch function
        }
    } while (choose != 0); // display first menu until user enter 0
}

void loarding_loop()
{
    int i;
    for (i = 0; i < 10000000; i++)
    {
    }
}

void loarding()
{
    int i; // this for loop
           // software name and other stuffs
    printf("\txxxxxxxx\txx\txxxxxxxx\t xxxxxxx\txxxxxxxx\txxxxxxxx\t xxxxxx \n");
    printf("\txx\t\txx\txx\t\txx\t\t   xx\t\t   xx\t\txx    xx\n");
    printf("\txxxxxx\t\txx\txxxxxx\t\txx\t\t   xx\t\t   xx\t\txx    xx\n");
    printf("\txx\t\txx\txx\t\txx\t\t   xx\t\t   xx\t\txx    xx\n");
    printf("\txxxxxxxx\txx\txxxxxxxx\t xxxxxxx\t   xx\t\txxxxxxxx\t xxxxxx \n");
    printf("\n\t \t\t\t\tDIGITALIZE VOTING SYSTEM OF UWU\n\n\t\t\t\t\t\t\tBY\n");
    printf("\n \t\t\t K.PRADISHAN \t  I.POWSIHAN\t  A.M.NUSNAN\t  K.THANUSHIKA\t  R.JOSHIGA\n\n\n");

    // printing loading section
    printf("\t");
    for (int i = 0; i < 100; i++)
    {
        printf("|");
        loarding_loop();
    }
}

int voting_status(int a, int b) // pass the registration number and course number for checking whether user already voted or not
{
    struct voter v1;
    FILE *fpvs;
    int f = 0;
    fpvs = fopen("voting status.uwu", "r");
    while (fread(&v1, sizeof(struct voter), 1, fpvs)) // read the file until the end of the record
    {
        if ((v1.reg_no == a) && (v1.cours == b))
        {
            f = 1;
        }
    }

    fclose(fpvs);

    return f; // get f as a return value
}

int vote_store(int x) // pass candidates nomination number to store vote
{
    struct cand c1;

    FILE *fpc;
    FILE *fpr;
    int found = 0;

    fpc = fopen("Candidate data.uwu", "r");
    while (fread(&c1, sizeof(struct cand), 1, fpc))
    {
        if (c1.nom_no == x)
        { // if candidates nomination there then add vote to result file and display conformation of voting
            found = 1;
            printf("\n you voted for");
            printf("\n\t%d \t========> \t %s\n", c1.nom_no, c1.cand_name);
            printf("\n THANK YOU");
            fpr = fopen("result.uwu", "a");

            fwrite(&x, sizeof(int), 1, fpr);
            fclose(fpr);
        }
    }
    if (!found)
    {
        printf("\n Candidate not found\n"); // if nomiation nuber not found then print
    }
    fclose(fpc);

    return found;
}

void voting_status_up(int rn, int cn)
{
    struct voter v1; // once voter vote then add voters details to voting status file
    FILE *fpv;
    FILE *fpvs;

    fpv = fopen("Voter data.uwu", "r");
    fpvs = fopen("voting status.uwu", "a");
    while (fread(&v1, sizeof(struct voter), 1, fpv))
    {
        if ((v1.reg_no == rn) && (v1.cours == cn)) // if registration number and cours numaber are correct then only save to the file
        {
            fwrite(&v1, sizeof(struct voter), 1, fpvs);
        }
    }
    fclose(fpv);
    fclose(fpvs);
}

void voting_section()
{
    struct voter v1;
    FILE *fpv;
    int n, x, rn, cn, nic, con, found = 0;

    fpv = fopen("Voter data.uwu", "r");
    // voting instruction menu
    printf(".........................................................................................................\n");
    printf(".........................................................................................................\n");
    printf(".........................................................................................................\n");
    printf("......................................Student\'s Union Election-2022......................................\n");
    printf(".........................................Uva Wellassa University.........................................\n");
    printf(".........................................................................................................\n\n");
    printf("This is Annual student\'s Union Election of Uva Wellassa University of 2022.\n\n");
    printf("Please note the following in voting......\n\n");
    printf("\t=>\tVoting will be open from 12.00pm to 3 pm ,27th January 2022.\n");
    printf("\t=>\tRead the Candidates name and their Nomination Numbers before Voting.\n");
    printf("\t=>\tPlease enter your accurate details.(If your details is correct\n\t\t\t\t\tthen you are eligible for voting process\n\t\t\t\t\t otherwise your vote will be rejected..)\n\n");
    printf("\t=>\tEligible voters please make sure that you are voting Independently on the welcome page.....\n");
    printf("\t=>\tplease enable the feature first......\n");
    printf("\t=>\tSelect the numbers to make your selections.....\n");
    printf("\t=>\tThe candidates you have selected will appear in order on the screen.....\n");
    printf("\t=>\tYou can't make changes after the selection.....\n");
    printf(".........................................................................................................\n");
    printf(".........................................................................................................\n");

    printf("\n<====================================================================================>\n");
    printf("enter registration number(eg:-20001):");
    scanf("%d", &rn);
    printf("\n<================you must course number=================>\n");
    cours_selec();
    printf("Enter course (eg:CST):");
    scanf("%d", &cn);
    printf("Enter last 4 digite of your NIC number:\n\t\t\teg:IF 200012345678\t THEN\t 5678\n\t\t\tOR\n\t\t\tIF 199912345V\t THEN\t 2345\nENTER:");
    scanf("%d", &nic);

    while (fread(&v1, sizeof(struct voter), 1, fpv))
    {
        if ((v1.reg_no == rn) && (v1.cours == cn) && (v1.nic == nic)) // check registration number ,course number and last 4 digite of nic
        {
            found = 1;
            n = v1.cours;
            printf("\nUWU/%s/%d \t \t %s", n_to_course(&n), v1.reg_no, v1.voter_name); // if all details are correct then print for confirmation
            printf("\n \t to confirm press 1 \t 0.exit\n");
            scanf("%d", &con);
            switch (con)
            {
            case 1:
                if (voting_status(rn, cn) == 1) // pass registration number,course number and check voting status
                {
                    printf("you already voted");
                }
                else
                {
                    display_cand(); // diplay the candidates name and number
                    printf("\nselec your choice:");
                    scanf("%d", &x);        // get voting nomination number
                    if (vote_store(x) == 1) // pass namination number save vote at result file and get confirmation 1
                    {

                        voting_status_up(rn, cn); // if vote added then pass voter details to voting status fuction for save that file
                    }
                }
                break;
            case 0:
                main(); // if user input o then call main function
                break;

            default:
                break;
            }
        }
    }
    if (!found)
    {
        printf("\n Voter  not found\n"); // if voter not found then print this
    }
    fclose(fpv);

    printf("\n<======================================================================================>\n");
}

void status_voter() // check if there any voter list was there or not
{
    FILE *fpv;
    if ((fpv = fopen("Voter data.uwu", "r")) == NULL) // tring to open that file in read mode
    {
        printf("\n<======================================================================================>\n");
        printf("choose 1 to  Create new list");
        printf("\n<======================================================================================>\n");
    }
    else
    {
        printf("\n<======================================================================================>\n");
        printf("all ready a list available choose 2 and see the list");
        printf("\n<======================================================================================>\n");
    }

    fclose(fpv);
}

char *n_to_course(int *n) // this programm for converting course number to course code
{
    char *cu;

    switch (*n)
    {
    case 1:
        cu = "CST";
        break;
    case 2:
        cu = "SCT";
        break;
    case 3:
        cu = "IIT";
        break;
    case 4:
        cu = "MRT";
        break;
    case 5:
        cu = "ENM";
        break;
    case 6:
        cu = "ANS";
        break;
    case 7:
        cu = "EAG";
        break;
    case 8:
        cu = "HTE";
        break;
    case 9:
        cu = "BST";
        break;
    case 10:
        cu = "BET";
        break;
    case 11:
        cu = "HRD";
        break;
    case 12:
        cu = "AQT";
        break;
    case 13:
        cu = "PLT";
        break;
    case 14:
        cu = "TEA";
        break;
    case 15:
        cu = "ICT";
        break;
    default:
        break;
    }
    return cu;
}

char cours_selec() // display course list for where ever i want
{
    printf("\n<================================COURSE LIST============================================>\n");
    printf("\n\tCST\t1.Computer science and technology  ");
    printf("\n\tSCT\t2.Science and technology");
    printf("\n\tIIT\t3.Industrial  information technology");
    printf("\n\tMRT\t4.Mineral resources and technology");
    printf("\n\tENM\t5Entrepreneurship  and technology and management");
    printf("\n\tANS\t6.Animal science ");
    printf("\n\tEAG\t7.Export agriculture");
    printf("\n\tHTE\t8.Hospitality ,tourism and events management ");
    printf("\n\tBST\t9.Bio system technology  ");
    printf("\n\tBET\t10.Engineering technology");
    printf("\n\tHRD\t11.Human resources department ");
    printf("\n\tAQT\t12.Aquatic resources technology ");
    printf("\n\tPLT\t13.Palm and latex technology value addition");
    printf("\n\tTEA\t14.tea technology value addition");
    printf("\n\tICT\t15.Informaiton and communication technology");
    printf("\n<======================================================================================>\n");

    printf("\nEnter your course number(eg:-1   for   CST):");
}

void Create_voterlist()
{
    struct voter *v;
    FILE *fpv;
    int n, i, ch;
    fpv = fopen("Voter data.uwu", "w");
    printf("\n<=======================================CREATE LIST===============================================>\n");
    printf("enter how many voters you want to add:");
    scanf("%d", &n);
    v = (struct voter *)calloc(n, sizeof(struct voter)); // we don't know about the number of voters amount exactly
                                                         // so here we are using dynamic memory allocation calloc for avoiting garbage value
    for (i = 0; i < n; i++)
    { // looping for n time
        printf("\n<===========================================NEW===========================================>\n");
        printf("Enter Registration number:(eg:-20001):");
        scanf("%d", &v[i].reg_no);
        printf("<===============ENTER THE COURSE================>\n1.Enter course number\t 2.See course list \nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter course number (eg:1  for  CST):");
            scanf("%d", &v[i].cours);
            break;
        case 2:
            cours_selec();
            scanf("%d", &v[i].cours);
            break;
        default:
            printf("\nInvalid input!!!!!!!!!! "); // if user enter different value then print course list again
            cours_selec();
            scanf("%d", &v[i].cours);
            break;
        }
        printf("Enter name:");
        scanf("%s", &v[i].voter_name);
        printf("Enter last 4 digit of your NIC number:\n\t\t\teg:IF 200012345678\t THEN\t 5678\n\t\t\tOR\n\t\t\tIF 199912345V\t THEN\t 2345\nENTER:");
        scanf("%d", &v[i].nic);
        fwrite(&v[i], sizeof(struct voter), 1, fpv);
    }
    printf("\n<=======================================SUCCESS FULL===============================================>\n");
    fclose(fpv);
}

void display_voter()
{
    struct voter v1;
    FILE *fpv;
    int n;
    fpv = fopen("Voter data.uwu", "r");
    printf("\n<========================================VOTER LIST==============================================>\n");
    while (fread(&v1, sizeof(struct voter), 1, fpv))
    {
        n = v1.cours; // for pass course number to n to course function for conversion

        printf("\nUWU/%s/%d \t %d \t %s\t", n_to_course(&n), v1.reg_no, v1.nic, v1.voter_name);
        printf("\n----------------------------------------------------------------------------\n");
    }

    printf("\n<==============================================================================================>\n");
    fclose(fpv);
}

void add_voter()
{ // like same as create voter list function but her we open the file in append mode
    struct voter *v;
    FILE *fpv;
    int n, i, ch;
    fpv = fopen("Voter data.uwu", "a");
    printf("\n<========================================ADD VOTER==============================================>\n");
    printf("enter how many voters you want add more :");
    scanf("%d", &n);
    v = (struct voter *)calloc(n, sizeof(struct voter));

    for (i = 0; i < n; i++)
    {

        printf("\n<======================================================================================>\n");
        printf("Enter Registration number:(eg:-20001):");
        scanf("%d", &v[i]);
        printf("<===============enter the course================>\n1.Enter course number\t 2.See course list \nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter course number(eg:1    for    CST):");
            scanf("%d", &v[i].cours);
            break;
        case 2:
            cours_selec();
            scanf("%d", &v[i].cours);
            break;
        default:
            printf("\nInvalid input!!!!!!!!!! ");
            cours_selec();
            scanf("%d", &v[i].cours);
            break;
        }

        printf("Enter name:");
        scanf("%s", &v[i].voter_name);
        printf("Enter last 4 digite of your NIC number:\n\t\t\teg:IF 200012345678\t THEN \t5678\n\t\t\tOR\n\t\t\tIF 199912345V\t THEN\t 2345\nENTER:");
        scanf("%d", &v[i].nic);

        fwrite(&v[i], sizeof(struct voter), 1, fpv);
    }
    fclose(fpv);

    printf("\n<========================================SUCCESS FULL==============================================>\n");
}

void del_voter()
{
    struct voter v1;
    FILE *fpv;
    FILE *fpv_temp;
    int cn, rn, found = 0;
    fpv = fopen("Voter data.uwu", "r");
    fpv_temp = fopen("Voter temp data.uwu", "w");

    printf("\n<=======================================DELETE===============================================>\n");
    printf("enter registration number to delete:(eg:-20001):  ");
    scanf("%d", &rn);
    printf("enter course number to delete:(eg:- 1     for     CST:  ");
    scanf("%d", &cn);

    while (fread(&v1, sizeof(struct voter), 1, fpv))
    {
        if ((v1.reg_no == rn) && (v1.cours == cn))
        {
            found = 1;
        }
        else
        {
            fwrite(&v1, sizeof(struct voter), 1, fpv_temp); // transfer all data to temp fille this ignores particular user data only
        }
    }
    fclose(fpv);
    fclose(fpv_temp);
    if (found)
    {
        fpv = fopen("Voter data.uwu", "w");
        fpv_temp = fopen("Voter temp data.uwu", "r");
        while (fread(&v1, sizeof(struct voter), 1, fpv_temp))
        {
            fwrite(&v1, sizeof(struct voter), 1, fpv); // transfer all data to voter data file from temp file
        }

        fclose(fpv);
        fclose(fpv_temp);
        printf("\n record deleted\n");
    }
    else
    {
        printf("\nVoter not found\n");
    }

    printf("\n<======================================================================================>\n");
}

void search_voter()
{ // like same as delete function but here this function going to print particular data
    struct voter v1;
    FILE *fpv;
    int n, rn, cn, found = 0;

    fpv = fopen("Voter data.uwu", "r");

    printf("\n<=====================================SEARCH=================================================>\n");
    printf("enter registration number to search(eg:-20001):");
    scanf("%d", &rn);
    printf("\n<================you must course number=================>\n");
    cours_selec();
    printf("Enter course (eg:CST):");
    scanf("%d", &cn);

    while (fread(&v1, sizeof(struct voter), 1, fpv))
    {
        if ((v1.reg_no == rn) && (v1.cours == cn))
        {
            found = 1; // for pass course number to n to course function for conversion
            n = v1.cours;
            printf("\nUWU/%s/%d \t \t %s", n_to_course(&n), v1.reg_no, v1.voter_name);
        }
    }
    if (!found)
    {
        printf("\n Voter  not found\n");
    }
    fclose(fpv);

    printf("\n<======================================================================================>\n");
}

void no_voter()
{ // counting number of records
    struct voter s1;
    FILE *fpv;
    fpv = fopen("Voter data.uwu", "r");

    printf("\n<========================================NUMBER OF VOTER==============================================>\n");
    fseek(fpv, 0, SEEK_END);                   // move to end of the file using fseek
    int n = ftell(fpv) / sizeof(struct voter); // ftell for current position of file so ftell/size
    printf("\n\nNumber of voter:%d", n);
    fclose(fpv);

    printf("\n<======================================================================================>\n");
}

void voter_data(){
    int ch;
    status_voter();
    do { // display_voter data menu
        printf("\n1.Create voter list\t2.Display list\t3.Add voter \t 4.Delete voter \t5.search voter\t 6.Number of voters\t 0.exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            Create_voterlist(); // calling create voter list function
            break;
        case 2:
            display_voter(); // calling display voter list function
            break;
        case 3:
            add_voter(); // calling add voter function
            break;
        case 4:
            del_voter(); // calling delete function
            break;
        case 5:
            search_voter(); // calling search voter function
            break;
        case 6:
            no_voter(); // calling number of voter function
            break;
        default:
            printf("Invalid input !!!!!!!!!!  try again");
            break; // if user enter invalid input then return to main function
        }
    } while (ch != 0);
}

void status_cand()
{ // check the if any candidates list is there or note
    FILE *fpc;
    if ((fpc = fopen("Candidate data.uwu", "r")) == NULL) // trying to open the candidates data file in read mode
    {
        printf("\n<======================================================================================>\n");
        printf("choose 1 to  Create new list");
        printf("\n<======================================================================================>\n");
    }
    else
    {
        printf("\n<======================================================================================>\n");
        printf("all ready a list available choose 2 and see the list");
        printf("\n<======================================================================================>\n");
    }

    fclose(fpc);
}

void Create_candlist()
{
    struct cand c[15]; // diclare an candidates array
    FILE *fpc;
    int i;
    fpc = fopen("Candidate data.uwu", "w");
    printf("\n<===============================================CREATE LIST===============================================>\n");
    printf("you must enter 15 candidates\n");
    for (i = 0; i < 15; i++) // loopm for 15 times
    {
        printf("\n<=================================================NEW=============================================>\n");
        printf("nomination number\t%d \t for", i + 1);
        c[i].nom_no = i + 1;
        printf("Enter name:");
        scanf("%s", &c[i].cand_name);

        fwrite(&c[i], sizeof(struct cand), 1, fpc);
    }
    fclose(fpc);
    printf("\n<============================================SUCCES FULL==================================================>\n");
}

void display_cand()
{ // display the candidates list
    struct cand c1;
    FILE *fpc;

    fpc = fopen("Candidate data.uwu", "r");
    printf("\n<==============================================LIST================================================>\n");
    while (fread(&c1, sizeof(struct cand), 1, fpc))
    {
        printf("\n\t%d \t========> \t %s\n", c1.nom_no, c1.cand_name);
        printf("\n-----------------------------------------------------------------\n");
    }

    fclose(fpc);
    printf("\n<==============================================================================================>\n");
}

void del_cand()
{
    struct cand c1;
    FILE *fpc;
    FILE *fpc_temp;
    int rn, found = 0;
    fpc = fopen("Candidate data.uwu", "r");
    fpc_temp = fopen("Candidate temp data.uwu", "w");
    printf("\n<================================================DELETE==============================================>\n");
    printf("enter nomination number to delete:");
    scanf("%d", &rn);

    while (fread(&c1, sizeof(struct cand), 1, fpc))
    {
        if (c1.nom_no == rn)
        {
            found = 1;
        }
        else
        {
            fwrite(&c1, sizeof(struct cand), 1, fpc_temp); //  transfer all data to temp file this function ingnores that particular data only
        }
    }
    fclose(fpc);
    fclose(fpc_temp);
    if (found)
    {
        fpc = fopen("Candidate data.uwu", "w");
        fpc_temp = fopen("Candidate temp data.uwu", "r");
        while (fread(&c1, sizeof(struct cand), 1, fpc_temp))
        {
            fwrite(&c1, sizeof(struct cand), 1, fpc); // transfer all the data to candidates data from temp file
        }

        fclose(fpc);
        fclose(fpc_temp);
        printf("\n record deleted\n");
        printf("\n<================================================SUCCES FULL==============================================>\n");
    }
    else
    {
        printf("\n<==============================================================================================>\n");
        printf("\nCandidate not found\n");
        printf("\n<==============================================================================================>\n");
    }
}

void serch_cand()
{
    struct cand c1;
    FILE *fpc;
    int rn, found = 0;
    fpc = fopen("Candidate data.uwu", "r");
    printf("\n<===============================================SEARCH===============================================>\n");
    printf("enter nomination number to serch:");
    scanf("%d", &rn);

    while (fread(&c1, sizeof(struct cand), 1, fpc))
    {
        if (c1.nom_no == rn)
        {
            found = 1; // if rn equal to nomination number then print then details fo candidates
            printf("\n\t%d \t========> \t %s\n", c1.nom_no, c1.cand_name);
        }
    }
    if (!found)
    {
        printf("\n Candidate not found\n");
    }
    fclose(fpc);
    printf("\n<==============================================================================================>\n");
}

void no_cand()
{ // same as number of voter function
    struct cand c1;
    FILE *fpc;
    fpc = fopen("Candidate data.uwu", "r");
    fseek(fpc, 0, SEEK_END);
    int n = ftell(fpc) / sizeof(struct cand);
    printf("\n<==============================================================================================>\n");
    printf("\n\nNumber of Candidate es:%d", n);
    printf("\n<==============================================================================================>\n");
    fclose(fpc);
}

void candidates_data()
{
    // cand == Candidate es
    // nom == nomination number
    int ch;
    status_cand();
    do
    {

        // display_cand menu

        printf("\n1.Create Candidate list\t2.Display list \t 3.Delete Candidate  \t4.Search Candidate \t 5.Number of Candidates \t 0.exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Create_candlist(); // calling create candidates function
            break;
        case 2:

            display_cand(); // calling function for display the candidates list

            break;

        case 3:
            del_cand(); // calling delete candidates function
            break;
        case 4:

            serch_cand(); // calling search candidates function

            break;

        case 5:
            no_cand(); // calling nuber of candidates function
            break;

        default:

            break;
        }
    } while (ch != 0);
}

void voting_result()
{
    struct cand c1;

    FILE *fpc;
    FILE *fpr;
    int x, n, i;
    int s[15] = {0}; // define an array and initialize with 0 for avoiting garbage value returning
    fpr = fopen("result.uwu", "r");

    fpc = fopen("Candidate data.uwu", "r");
    // read the data and store into allocated array by using switch
    while (fread(&x, sizeof(int), 1, fpr))
    {
        switch (x)
        {
        case 1:
            s[0]++;
            break;
        case 2:
            s[1]++;
            break;
        case 3:
            s[2]++;
            break;
        case 4:
            s[3]++;
            break;
        case 5:
            s[4]++;
            break;
        case 6:
            s[5]++;
            break;
        case 7:
            s[6]++;
            break;
        case 8:
            s[7]++;
            break;
        case 9:
            s[8]++;
            break;
        case 10:
            s[9]++;
            break;
        case 11:
            s[10]++;
            break;
        case 12:
            s[11]++;
            break;
        case 13:
            s[12]++;
            break;
        case 14:
            s[13]++;
            break;
        case 15:
            s[14]++;
            break;
        default:
            break;
        }
    }
    // print all vote nomination nuber vise
    printf("\n<==============================================LIST================================================>\n");
    printf("\n\t \t \t\tvote count\n");
    while (fread(&c1, sizeof(struct cand), 1, fpc))
    {
        printf("\n\t%d \t========>\t%d\t <=======\t %s\n", c1.nom_no, s[c1.nom_no - 1], c1.cand_name);
        printf("\n-----------------------------------------------------------------\n");
    }

    fclose(fpc);
    fclose(fpr);
    printf("\n<==============================================================================================>\n");
}

void result()
{ // ask three password from user for improve security of result data
    int pass1, pass2, pass3;
    printf("=>Enter the Password1:");
    scanf("%d", &pass1);
    if (pass1 == 1111)
    {
        printf("=>Enter the Password2:");
        scanf("%d", &pass2);
        if (pass2 == 2222)
        {
            printf("=>Enter the Password3:");
            scanf("%d", &pass3);
            if (pass3 == 3333)
            {
                voting_result(); // calling voting result function
            }

            else
            {
                printf("\tInvalid password3..!\n");
                printf("\n<======================================================================================>\n");
            }
        }

        else
        {
            printf("\tInvalid password2..!\n");
        }
    }

    else
    {
        printf("\tInvalid password1..!\n");
        printf("\n<======================================================================================>\n");
    }
}

void password_2()
{ // this function for ask password 2 from user if password correct then enter to the voter data function

    int pass2;
    printf("=>Enter the Password2:");
    scanf("%d", &pass2);
    if (pass2 == 2222)
    {
        voter_data(); // calling voter data function
    }

    else
    {
        printf("\tInvalid password..!\n");
        printf("\n<======================================================================================>\n");
    }
}

void password_3()
{ // this function for ask password 3 from user if password correct then enter to the candidates data function

    int pass3;
    printf("=>Enter the Password3:");
    scanf("%d", &pass3);

    if (pass3 == 3333)
    {
        candidates_data(); // calling candidates data function
    }
    else
    {
        printf("\tInvalid password..!\n");
        printf("\n<======================================================================================>\n");
    }
}

void reset()
{
    // this function ask super admin password from user and the reset voting by opening voting status file,result file in write mode

    char pw[6] = "pradee";
    char n[8];
    int i = 0;
    char ch;
    printf("\n\t\tENTER SUPER ADMIN PASSWORD TO RESET VOTING\n\t\t\t");
    printf("Password:");

    while (1)
    {
        ch = getch(); // get key

        if (ch == 13) // for enter
        {
            n[i] = '\0';  // null termination characher
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--; // go to previous position
                printf("\b \b"); // for backspace
            }
        }
        else
        {
            n[i++] = ch;
            printf("X"); // to replace password character with *
        }
    } // while ends here

    printf("\n");

    if (n[0] == pw[0] && n[1] == pw[1] && n[2] == pw[2] && n[3] == pw[3] && n[4] == pw[4] && n[5] == pw[5])
    {
        FILE *fpr;
        FILE *fpvs;
        fpvs = fopen("voting status.uwu", "w");
        fpr = fopen("result.uwu", "w");
        fclose(fpvs);
        fclose(fpr);
        printf("\nRESET SUCCES FULL\n");
    }
    else
    {

        printf("\nIVALID PASSWORD!\nTRY AGAIN\a \n");
    }
}

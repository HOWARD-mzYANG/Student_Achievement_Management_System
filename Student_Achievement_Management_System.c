#include <stdio.h>
#include <string.h>

#define MAX_NUM 30
#define MAX_COURSE 6

typedef struct
{
    int num;
    float score[MAX_COURSE];
    float sum;
    float average;
    char *name;
} stu;

int Menu(void);
void Input_record(stu *student[], int n, int m);
void Calculate_total_and_average_score_of_every_course(stu *student[], int n, int m);
void Calculate_total_and_average_score_of_every_student(stu *student[], int n, int m);
void Sort_in_descending_order_by_total_score_of_every_student(stu *student[], int m);
void Sort_in_ascending_order_by_total_score_of_every_student(stu *student[], int m);
void Sort_in_ascending_order_by_number(stu *student[], int m);
void Sort_in_dictionary_order_by_name(stu *student[], int m);
void Search_by_number(student, Number_of_students);
void Search_by_name(student, Number_of_students);
void Statistic_analysis_for_every_course(stu *student[], int m, int n);
void List_record(stu *student[], int m);
void Write_to_a_file(stu *student[], int m, char *filename);
void Read_from_file(stu *student[], char *filename);



int main()
{
    printf("2310461226  吴龙坤\n");


    stu *student[MAX_NUM];

    int Number_of_students,Number_of_course;
    printf("Input student number(m<30) and student course(n<6):");
    if (scanf("%d" ,&Number_of_students) != 1 || scanf("%d" ,&Number_of_course) != 1)
    {
        printf("Invalid input");
    }

    while (1)
    {
        int ch = Menu();
        switch (ch) 
        {
            case 1:
                Input_record(student,Number_of_course,Number_of_students);
                break;
            case 2:
                Calculate_total_and_average_score_of_every_course(student,Number_of_course,Number_of_students);
                break;
            case 3:
                Calculate_total_and_average_score_of_every_student(student,Number_of_course,Number_of_students);
                break;
            case 4:
                Sort_in_descending_order_by_total_score_of_every_student(student, Number_of_students);
                break;
            case 5:
                Sort_in_ascending_order_by_total_score_of_every_student(student, Number_of_students);
                break;
            case 6:
                Sort_in_ascending_order_by_number(student, Number_of_students);
                break;
            case 7:
                Sort_in_dictionary_order_by_name(student, Number_of_students);
                break;
            case 8:
                Search_by_number(student, Number_of_students);
                break;
            case 9:
                Search_by_name(student, Number_of_students);
                break;
            case 10:
                Statistic_analysis_for_every_course(student, Number_of_students, Number_of_course);
                break;
            case 11:
                List_record(student, Number_of_students);
                break;
            case 12:
                Write_to_a_file(student, Number_of_students);
                break;
            case 13:
                Read_from_file(student,);
                break;
        }
    }
}

void Swap(stu *a,stu *b)
{
 stu temp;
 temp=*a;
 *a=*b;
 *b=temp;
}

int Menu(void) 
{
    char *menu[] = 
    {
        "1. Input record\n",
        "2. Calculate total and average score of every course\n",
        "3. Calculate total and average score of every student\n",
        "4. Sort in descending order by total score of every student\n",
        "5. Sort in ascending order by total score of every student\n",
        "6. Sort in ascending order by number\n",
        "7. Sort in dictionary order by name\n",
        "8. Search by number\n",
        "9. Search by name\n",
        "10. Statistic analysis for every course\n",
        "11. List record\n",
        "12. Write to a file\n",
        "13. Read from file\n",
        "0. Exit\n"
    };

    for (int i = 0; i < 14; i++)
    {
        printf("%s", menu[i]);
    }
    printf("\nPlease enter your choice: ");

    //选择选项
    int choice;
    if (scanf("%d", &choice) != 1) 
    {
        printf("Invalid input");
    }
    return choice;
}

void Input_record(stu *student[], int n, int m) 
{
    printf("Inpuit student's ID,name and score");
    for (int i = 0; i < m; i++)
    {
        scanf("%d%s" ,student[i]->num,student[i]->name);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", student[i]->score[j]);
        }    
    }
}

void Calculate_total_and_average_score_of_every_course(stu *student[],int n,int m)
{
    float *sum_course[n];
    float *aver_course[n];
    for (int i = 0; i < n; i++)
    {
        *sum_course[i] = 0;
        for (int j = 0; j < m; j++)
        {
            *sum_course[i] += (float)student[i]->score[j];
        }
        *aver_course[i] =  *sum_course[i]/n;
    }
    
}

void Calculate_total_and_average_score_of_every_student(stu *student[],int n,int m)
{
    float *sum_stu = 0;
    float *aver_stu;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *sum_stu += (float)student[i]->score[j];
        }      
    }
    *aver_stu = *sum_stu/m;
}

//学生总成绩升序排列
void Sort_in_descending_order_by_total_score_of_every_student(stu *student[], int m)
{
  for (int i = 0; i < m - 1; ++i) 
  {
    for (int j = i + 1; j < m; ++j)
    {
      if (student[i]->sum < student[j]->sum) //比较两个学生的总分
      {
        Swap(student[i], student[j]); //如果需要交换,调用Swap函数交换两个学生的位置
      }
    }
  }
}

//学生总成绩升序排列
void Sort_in_ascending_order_by_total_score_of_every_student(stu *student[], int m)
{
  for (int i = 0; i < m - 1; ++i)
  {
    for (int j = i + 1; j < m; ++j) 
    {
      if (student[i]->sum > student[j]->sum) 
      {
        Swap(student[i], student[j]);
      }
    }
  }
}

//按学号升序排列
void Sort_in_ascending_order_by_number(stu *student[], int m)
{
  for (int i = 0; i < m - 1; ++i)
  {
    for (int j = i + 1; j < m; ++j)
    {
      if (student[i]->num > student[j]->num)
      {
        Swap(student[i], student[j]);
      }
    }
  }
}

//按姓名字典顺序排序  
void Sort_in_dictionary_order_by_name(stu *student[], int m)
{
  for (int i = 0; i < m - 1; ++i) 
  {
    for (int j = i + 1; j < m; ++j)
    {
      if (strcmp(student[i]->name, student[j]->name) > 0)
      {
        Swap(student[i], student[j]);
      }
    }
  }
}

//按学号查找
void Search_by_number(stu *student[], int m) 
{
  //获取学号
  int number;
  printf("Input your number:");
  if (scanf("%d", &number) != 1)
  {
    printf("Invalid input");
  }

  for (int i = 0; i < m; ++i)
  {
    if (student[i]->num == number)
    {
      printf("Found: \n");
      printf("Number: %d\n", student[i]->num); 
      printf("Name: %s\n", student[i]->name);
      printf("Scores: ");
      for (int j = 0; j < MAX_COURSE; ++j) 
      {
        printf("%f ", student[i]->score[j]);
      }
      printf("\n");
      return;
    }
  }
  printf("Not found!\n");
}

//按姓名查找
void Search_by_name(stu *student[], int m)
{
  //获取名字
  char *name;
  printf("Input your name");
  if (scanf("%s" ,&name) != 1)
  {
    pirntf("Invalid input");
  }

  for (int i = 0; i < m; ++i)
  {
    if (strcmp(student[i]->name, name) == 0) 
    {
      printf("Found: \n");
      printf("Number: %d\n", student[i]->num);
      printf("Name: %s\n", student[i]->name); 
      printf("Scores: ");
      for (int j = 0; j < MAX_COURSE; ++j)  
      {
        printf("%f ", student[i]->score[j]);
      }
      printf("\n");
      return;
    }
  }
  printf("Not found!\n");
}

//对每门课程统计分析
void Statistic_analysis_for_every_course(stu *student[], int m, int n)  
{
  float sum[MAX_COURSE] = {0};
  float max[MAX_COURSE] = {0};
  float min[MAX_COURSE] = {100};

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      sum[j] += student[i]->score[j];
      if (student[i]->score[j] > max[j])
        max[j] = student[i]->score[j];
      if (student[i]->score[j] < min[j]) 
        min[j] = student[i]->score[j];
    }
  }

  for (int i = 0; i < n; ++i)
  {
    printf("Course %d:\n", i+1);
    printf("Max score: %.2f\n", max[i]);
    printf("Min score: %.2f\n", min[i]);
    printf("Average score: %.2f\n\n", sum[i] / m);
  }
}

//列出所有学生记录
void List_record(stu *student[], int m)
{
  for (int i = 0; i < m; ++i)
  {
    printf("Number: %d\n", student[i]->num);
    printf("Name: %s\n", student[i]->name);
    printf("Scores: ");
    for (int j = 0; j < MAX_COURSE; ++j) 
    {
      printf("%.2f ", student[i]->score[j]); 
    }
    printf("\n");
  }
}

//写入文件
void Write_to_file(stu *student[], int m)
{
  char *filename = "students.txt";
  
  FILE *fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }

  for (int i = 0; i < m; ++i)
  {
    fprintf(fp, "%d %s", student[i]->num, student[i]->name);
    for (int j = 0; j < MAX_COURSE; ++j)
    {
      fprintf(fp, " %.2f", student[i]->score[j]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  printf("Write to file %s successfully!\n", filename);
}

//从文件读取
void Read_from_file(stu *student[], char *filename) 
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error opening file!\n");
    return;
  }

  int i = 0;
  while (fscanf(fp, "%d %s", &student[i]->num, student[i]->name) != EOF) 
  {
    for (int j = 0; j < MAX_COURSE; ++j)
    {
      fscanf(fp, "%f", &student[i]->score[j]);
    }
    ++i;
  }

  fclose(fp);
  printf("Read from file %s successfully!\n", filename);
}

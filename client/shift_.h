#ifndef SHIFT__H
#define SHIFT__H


void MainWindow::shift_matrix(QLineEdit* matrix[COLUMS_])
{
   int r;
   for(r = 0 ; r < ROWS_*COLUMS_-COLUMS_;  r++)
      matrix[r]->setText(matrix[r+COLUMS_]->text());
}
void MainWindow::shift_memory(QString matrix[][COLUMS_])
{
   int r,s;
   for(r=0; r<ROWS_*MOLTI-COLUMS_;r++)
       for(s=0; s<COLUMS_;s++)
           matrix[r][s] = matrix[r+1][s];
}



#endif // SHIFT__H

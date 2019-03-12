

my $array =[
['O','O','O','X','O','O','O'],
['O','O','X','X','O','X','O'],
['O','X','O','O','O','X','O'],
];

my $hash = {};

my $rowend = 2;
$colend = 6;


my $row =0;
my $col = 0;

my $totalcount = 0;

for (my $i = $rowend; $i >=0; $i--) {
    for ( my $j = $colend; $j >=0; $j--){
        if ( $array->[$i]->[$j] eq 'X'){
            $totalcount++;
            $row = $i;
            $col = $j;
            $hash->{$i.$j} = 0;
        }
    }
}


my $count = recursive($row, $col);
my $cycle = 1;

while ( $totalcount - $count > 0 ){
    
    foreach my $each ( sort keys %$hash) {
        if ( $hash->{$each} == 0 ){
            ($row, $col) = $each =~ /(\d)(\d)/;
            break;
        }
    }
    
    $count += recursive($row, $col);
    $cycle++;
}


sub recursive{
    my ($row, $col) = @_;
    my $count = 0;

    if ( $array->[$row]->[$col] eq 'X'){
        $hash->{$row.$col} = 1;
        $count++;
    }
    
    
        
    if ( $row-1 >= 0 && $array->[$row-1]->[$col] eq 'X' && $hash->{($row-1).$col} != 1) {$count += recursive($row-1 , $col) } ;
    if ( $row+1 <= $rowend && $array->[$row+1]->[$col] eq 'X' && $hash->{($row+1).$col} != 1) { $count += recursive($row+1, $col)};
    if ( $col-1 >= 0 && $array->[$row]->[$col-1] eq 'X' && $hash->{($row).($col-1)} != 1) {$count += recursive($row, $col-1)};
    if ( $col+1 <=$colend && $array->[$row]->[$col+1] eq 'X' && $hash->{($row).($col+1)} != 1) {$count +=  recursive($row, $col+1)};
        
        
    return $count;
}



print "result = $cycle \n";


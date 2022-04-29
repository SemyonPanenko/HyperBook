#! /bin/bash
input_directory=$1  

output_result=($(ls ${input_directory}))

resuling_file=${input_directory}/all_contents.txt
rm -f ${resuling_file}
touch ${resuling_file}

for file_name in "${output_result[@]}"
do 
    echo ${input_directory}/${file_name} >> ${resuling_file}
done
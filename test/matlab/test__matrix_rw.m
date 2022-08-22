%********
%* setup
%********
io_config;
test_name = 'test-matrix_rw';
dat_prefix = append(dat_dir, '/', test_name, '-');
exe_name = append(test_name, '.exe');
in_arr_fname = 'in_arr.dat';
out_arr_fname = 'out_arr.dat';

n_dim = 150;
m_dim = 75;

error_thres = 1e-16;

%* __USE_SINGLE_PRECISION__ 
%* error_thres = 1e-6; 

%*******************
%* create test data 
%*******************
in_arr = [magic(m_dim); magic(m_dim)]./1e3 - 1/3;

%************************************
%* write input (for test executable)
%************************************
writematrix(in_arr, append(dat_prefix, in_arr_fname), 'Delimiter', delimiter);  

%***************************
%* call the test executable
%***************************
prev_pwd = pwd;
cd(bin_dir);

if ~isfile(exe_name)
	error(append(bin_dir, '/', exe_name, ' does not exist. Use CMake to build the test.'));
end

if system(exe_name) > 0
	warning(append(bin_dir, '/', exe_name, ' has returned failure.'));
end

cd(prev_pwd);

%******************************************
%* read output (created by the executable)
%******************************************
out_arr = readmatrix(append(dat_prefix, out_arr_fname));

%*********
%* verify
%*********
max_error = max(in_arr - out_arr, [], 'all');

if max_error < error_thres
    disp(append(test_name, '	ok'));
else
    disp(append(test_name, '	fail'));
end
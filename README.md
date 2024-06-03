# Fork Implementation in xv6

## Author
**Mrugank Jadhav**

---

## Description
1. **System Call to Implement 'shutdown' Command**
2. **System Call to Change 'fork' Policy**: 
   - **1**: Parent First Policy
   - **2**: Child First Policy
3. **System Call to Change Scheduler Policy**: 
   - **1**: Round Robin
   - **2**: Stride

---

## Implementation Details
1. **'shutdown' Command**:
   - Implemented a system call to safely shut down the operating system.
   - Added the corresponding system call handler and updated the system call table.

2. **'fork' Policy**:
   - Implemented a system call to change the `fork` policy between Parent First and Child First.
   - Modified the `fork` implementation to check the policy and schedule the parent or child process accordingly.

3. **Scheduler Policy**:
   - Implemented a system call to switch between Round Robin and Stride scheduling policies.
   - Integrated the scheduler policy change in the system scheduler to handle the different scheduling algorithms.

---

## Test Cases
### Test Case Results
The results of the test cases can be found in the `TEST_CASES.txt` file.

### Test Cases
1. **Test Case 0: Default (Round Robin) Scheduler, 3 Processes**
   - Expected output pattern showing three processes in a round robin scheduling pattern.
   
2. **Stride Scheduling Test Case 1**
   - Two child processes with no transfer.
   - Expected output pattern showing stride scheduling between processes.

3. **Stride Scheduling Test Case 2**
   - One child process, parent transfers 1/2 of its tickets at the beginning.
   - Expected output pattern showing the effect of ticket transfer on process execution.

4. **Fork Test with Child as the Fork Winner**
   - The fork test where the child process is set as the fork winner.
   - Expected output showing the child process execution first for 50 trials.

5. **Fork Test with Parent as the Fork Winner**
   - The fork test where the parent process is set as the fork winner.
   - Expected output showing the parent process execution first for 50 trials.
  

### Test Case Results
The results of the test cases can be found in the `TEST_CASES.txt` file.

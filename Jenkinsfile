pipeline {
    agent any
    tools{
        ant '1.10.14'
    }
    stages {
        stage('Checkout Code') {
            steps {
                checkout([
                    $class: 'GitSCM',
                    branches: [[name: 'main']],  
                    userRemoteConfigs: [[url: 'https://github.com/vemulasaikrishna03/Venkys.io.git']], 
                ])
            }
        }
        stage('Code Execution') {
            steps {
                script {
                    def codeDir = './folder1'
                    def javaFiles = getChangedFiles(codeDir, '**/*.java')
                    def cppFiles = getChangedFiles(codeDir, '**/*.cpp')
                    def pythonFiles = getChangedFiles(codeDir, '**/*.py')

                    if (javaFiles) {
                        echo "Java code changes detected in the following files:"
                        echo javaFiles.join('\n')

                        for (def file : javaFiles) {
                            def className = file.replaceAll('.*/(.*).java', '$1')
                            def buildpath = 'Java/build.xml'
                            try {
                                bat "ant -f $buildpath -Djava.file=$file -Dmain.class=$className compile"
                                echo "Java code in $file compiled successfully."
                                // TODO Store .class files in the Artifactory director  ghfht
                            } catch (Exception e) {
                                error "Error in $file: $e.getMessage()"
                            }
                        }
                    } else {
                        echo "No Java code changes detected in known code directories."
                    }

                    if (cppFiles) {
                        echo "C++ code changes detected in the following files:"
                        echo cppFiles.join('\n')

                        for (def file : cppFiles) {
                            // TODO Execute C++ code here (similar to the previous stage)
                            // ...
                            // Store .exe files in the Artifactory directory
                        }
                    } else {
                        echo "No C++ code changes detected in known code directories."
                    }

                    if (pythonFiles) {
                        echo "Python code changes detected in the following files:"
                        echo pythonFiles.join('\n')

                        for (def file : pythonFiles) {
                            def result = bat(script: "python $file", returnStatus: true)
                            if (result == 0) {
                                echo "Success: Python script executed successfully."
                                //TODO Store .py files in the Artifactory directory
                            } else {
                                error "Failure: Python script execution failed with exit code $result."
                            }
                        }
                    } else {
                        echo "No Python code changes detected in known code directories."
                    }
                }
            }
        }
    }

    post {
        always {
           //TODO:mail part here 
        }
    }
}

@NonCPS
List<String> getChangedFiles(String directory, String filePattern) {
    def changedFiles = []
    for (changeLogSet in currentBuild.changeSets) {
        for (entry in changeLogSet.getItems()) {
            if (entry.affectedPaths.any { it.startsWith(directory) && it.endsWith(filePattern) }) {
                changedFiles.add(entry.filePath)
            }
        }
    }
    return changedFiles
}
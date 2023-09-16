pipeline {
    agent any

    stages {
        stage('Install JFrog CLI') {
            steps {
                script {
                    // Define the URL to download the JFrog CLI
                    def jfrogCliUrl = 'https://releases.jfrog.io/artifactory/jfrog-cli/v2-jfrog-cli-windows-amd64/jfrog.exe'

                    // Define the path where you want to install the JFrog CLI
                    def installPath = "${env:USERPROFILE}\\Downloads\\jfrog.exe"

                    // Download the JFrog CLI
                    powershell """
                    Start-Process -Wait -Verb RunAs powershell '-NoProfile iwr $jfrogCliUrl -OutFile $installPath'
                    """

                    // Verify the installation
                    powershell """
                    $installedVersion = & $installPath --version
                    Write-Host "Installed JFrog CLI version: $installedVersion"
                    """
                }
            }
            
        }

        stage('Create Repository') {
            steps {
                script {
                    // Define your code, today's date, and today's time
                    def code = "your_code_here"  // Replace with your desired code
                    def currentDate = new Date().format('yyyyMMdd')
                    def currentTime = new Date().format('HHmmss')

                    // Construct the repository name
                    def repositoryName = "${code}_${currentDate}_${currentTime}"

                    // Configure Artifactory server details (update with your server details)
                    def artifactoryServerUrl = 'https://your-artifactory-instance/artifactory'
                    def artifactoryRepoKey = 'your-artifactory-repo-key'
                    def artifactoryUsername = 'your-username'
                    def artifactoryPassword = 'your-password'

                    // Create the repository using JFrog CLI
                    def createRepoCmd = "jfrog rt rc --url='${artifactoryServerUrl}' --user='${artifactoryUsername}' --password='${artifactoryPassword}'"
                    def createRepoCmdArgs = "create-repo ${repositoryName} ${artifactoryRepoKey}"

                    sh "${createRepoCmd} ${createRepoCmdArgs}"
                }
            }
        }

        // Add additional stages for your pipeline
    }

    // Add post-build actions or other pipeline configurations
}

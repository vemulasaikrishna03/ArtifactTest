pipeline {
    agent any

    stages {
        stage('Create Repository') {
            steps {
                script {
                    
                    def currentDate = new Date().format('yyyyMMdd')
                    def currentTime = new Date().format('HHmmss')
                   

                    def repositoryName = "${currentDate}_${currentTime}_code"

                    // Configure JFrog Artifactory server
                    def jfrogServer = Artifactory.server('Artifactory')

                    // Create the repository
                    jfrogServer.newRepository(
                        serverId: 'Artifactory',
                        repoKey: repositoryName,
                        description: "Repository created on ${currentDate} ${currentTime} with code ",
                        packageType: 'generic',
                        notes: "Repository created by Jenkins"
                    )
                }
            }
        }
    }
}

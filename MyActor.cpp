// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    // StaticMeshComponent 생성 및 초기화
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    // 메쉬 설정 (엔진에 기본 제공 메쉬 사용)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }

    // 초기 위치 설정
    SetActorLocation(FVector(0.0f, 0.0f, 0.0f)); // 월드 좌표 (0, 0, 0)으로 설정

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("MyActor has spawned at: %s"), *GetActorLocation().ToString());
    //UE_LOG(LogTemp, Warning, TEXT("im a live"));

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

